#include "framework.h"
#include "ShaderManager.h"

ShaderManager* ShaderManager::_instance = nullptr;

ShaderManager::ShaderManager()
{
}

ShaderManager::~ShaderManager()
{
}

shared_ptr<VertexShader> ShaderManager::AddVS(wstring file)
{
	shared_ptr<VertexShader> result;
	if (_shaderTable.count(file) == 0)
	{
		result = make_shared<VertexShader>(file);
		_shaderTable[file] = result;

		return result;
	}
	else
		return static_pointer_cast<VertexShader>(_shaderTable[file]);
}

shared_ptr<PixelShader> ShaderManager::AddPS(wstring file)
{
	shared_ptr<PixelShader> result;
	if (_shaderTable.count(file) == 0)
	{
		result = make_shared<PixelShader>(file);
		_shaderTable[file] = result;

		return result;
	}
	else
		return static_pointer_cast<PixelShader>(_shaderTable[file]);
}
