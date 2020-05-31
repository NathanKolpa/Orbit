#pragma once
#include "ShaderSource.hpp"
#include "ShaderRequirementError.hpp"

namespace orb
{
	class ShaderResource
	{
	public:
		explicit ShaderResource(ShaderSource* openglVertexShader = nullptr, ShaderSource* openglFragmentShader = nullptr);
	public:
		const ShaderSource& requireOpenglVertexShader() const;
		const ShaderSource& requireOpenglFragmentShader() const;
	private:
		ShaderSource* m_openglVertexShader;
		ShaderSource* m_openglFragmentShader;
	};
}