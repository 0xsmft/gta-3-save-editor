/********************************************************************************************
*                                                                                           *
*                                                                                           *
*                                                                                           *
* MIT License                                                                               *
*                                                                                           *
* Copyright (c) 2020 - 2026 BEAST                                                           *
*                                                                                           *
* Permission is hereby granted, free of charge, to any person obtaining a copy              *
* of this software and associated documentation files (the "Software"), to deal             *
* in the Software without restriction, including without limitation the rights              *
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell                 *
* copies of the Software, and to permit persons to whom the Software is                     *
* furnished to do so, subject to the following conditions:                                  *
*                                                                                           *
* The above copyright notice and this permission notice shall be included in all            *
* copies or substantial portions of the Software.                                           *
*                                                                                           *
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR                *
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,                  *
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE               *
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER                    *
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,             *
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE             *
* SOFTWARE.                                                                                 *
*********************************************************************************************
*/

#pragma once

#include "Base.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

class Log
{
public:
	XY_SINGLETON_LAZY( Log )

public:
	Log();
	~Log();

	void Init();
	void Clear();

	std::shared_ptr<spdlog::logger>& CoreLogger() { return m_CoreLogger; }
	std::shared_ptr<spdlog::logger>& ClientLogger() { return m_ClientLogger; }

private:
	std::shared_ptr<spdlog::logger> m_CoreLogger;
	std::shared_ptr<spdlog::logger> m_ClientLogger;
};
	
// Core log macros
#define XY_CORE_TRACE(...)				::Log::Get().CoreLogger()->trace(__VA_ARGS__)
#define XY_CORE_INFO(...)				::Log::Get().CoreLogger()->info(__VA_ARGS__)
#define XY_CORE_WARN(...)				::Log::Get().CoreLogger()->warn(__VA_ARGS__)
#define XY_CORE_ERROR(...)				::Log::Get().CoreLogger()->error(__VA_ARGS__)
#define XY_CORE_FATAL(...)				::Log::Get().CoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define XY_TRACE(...)					::Log::Get().ClientLogger()->trace(__VA_ARGS__)
#define XY_INFO(...)					::Log::Get().ClientLogger()->info(__VA_ARGS__)
#define XY_WARN(...)					::Log::Get().ClientLogger()->warn(__VA_ARGS__)
#define XY_ERROR(...)					::Log::Get().ClientLogger()->error(__VA_ARGS__)
#define XY_FATAL(...)					::Log::Get().ClientLogger()->critical(__VA_ARGS__)
