#pragma once

class FTimestep
{
public:
	FTimestep() {}
	FTimestep( float time ) : m_Time( time ) {}

	inline float Seconds() const { return m_Time; }
	inline float Milliseconds() const { return m_Time * 1000.0f; }

	operator float() { return m_Time; }

private:

	float m_Time = 0.0f;
};
