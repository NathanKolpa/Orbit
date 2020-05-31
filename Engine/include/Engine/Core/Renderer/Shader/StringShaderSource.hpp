#pragma once
#include "ShaderSource.hpp"

namespace orb
{
	class StringShaderSource : public ShaderSource
	{
	public:
		StringShaderSource(std::string source);
	public:
		std::string getSource() const override;
	private:
		std::string m_source;
	};
}