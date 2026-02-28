#include "sppch.h"
#include "SaveFile.h"

#include "Base/BufferHelpers.h"

#include <fstream>

FGtaSaveFile::FGtaSaveFile()
{
}

FGtaSaveFile::~FGtaSaveFile()
{
}

bool FGtaSaveFile::Read( const std::filesystem::path& rPath )
{
	std::ifstream stream( rPath, std::ios::binary | std::ios::in );
	
	FBufferHelpers::Skip4( stream );
	FBufferHelpers::ReadObject( m_SaveFile.SimpleData, stream );

	m_SaveFile.TheScriptsData.Read( stream );
	m_SaveFile.PlayerPedsData.Read( stream );
	m_SaveFile.Garages.Read( stream );
//	m_SaveFile.Vehicles.Read( stream );
//	m_SaveFile.Objects.Read( stream );

	stream.close();

	return true;
}
