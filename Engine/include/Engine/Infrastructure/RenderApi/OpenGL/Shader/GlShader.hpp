#pragma once
#ifdef ORB_OPENGL

#include <Engine/Core/Renderer/Shader/Shader.hpp>
#include <Engine/Core/pch.hpp>

namespace orb
{
	class GlShader: public Shader
	{
	public:
		static GlShader* create(const std::string& vertexSource, const std::string& fragmentSource);
	private:
		explicit GlShader(unsigned  int shaderId);
	public:
		void bind() override;
		void unBind() override;
	private:
		void loadUniforms();
	private:
		static unsigned int s_boundShader;
		std::unordered_map<std::string, unsigned int> m_uniformLocations;
		unsigned int m_shaderId;
	};
}

#endif