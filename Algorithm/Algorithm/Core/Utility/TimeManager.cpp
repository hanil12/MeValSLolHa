#include "framework.h"
#include "TimeManager.h"

TimeManager* TimeManager::_instance = nullptr;

TimeManager::TimeManager()
{
	QueryPerformanceFrequency((LARGE_INTEGER*)&_periodFrequency); // 1초당 CPU 진동수 : 100

	QueryPerformanceCounter((LARGE_INTEGER*)&_lastTime); // 최근 마지막 진동수 : 0

	_timeScale = 1.0 / (double)_periodFrequency;
}

TimeManager::~TimeManager()
{

}

void TimeManager::Update()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&_curTime); // 현재 Update 진동수 : 110
	_deltaTime = (double)(_curTime - _lastTime) * _timeScale; // cur(110), last(100) => 10 /  1초당 CPU 진동수 => 1번 업데이트에 흘러간 시간

	// lockFPS : 프레임 고정
	if (_lockFPS != 0)
	{
		// 반복문으로 Update 제어
		while (_deltaTime < (1.0 / _lockFPS))
		{
			QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
			_deltaTime = (double)(_curTime - _lastTime) * _timeScale;
		}
	}

	_lastTime = _curTime; // last : 100

	_frameCount++;
	_oneSecCount += _deltaTime;

	// 실제 1초가 흘렀다.
	if (_oneSecCount > 1.0)
	{
		_oneSecCount = 0.0;
		_frameRate = _frameCount; // frameRate : 1초에 몇번 업데이트가 되었는지
		_frameCount = 0;
	}

	_runTime += _deltaTime; // 실제 게임이 진행된 시간
}
