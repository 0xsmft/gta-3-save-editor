#include "sppch.h"
#include "SaveFile.h"

#include "Core/BufferHelpers.h"

#include <fstream>

FSaveFile::FSaveFile()
{
}

FSaveFile::~FSaveFile()
{
}

bool FSaveFile::Read( const std::filesystem::path& rPath )
{
	std::ifstream stream( rPath, std::ios::binary | std::ios::in );
	
	FBufferHelpers::Skip4( stream );
	FBufferHelpers::ReadObject( m_SaveFile.SimpleData, stream );

	m_SaveFile.TheScriptsData.Read( stream );
	m_SaveFile.PlayerPedsData.Read( stream );
	m_SaveFile.Garages.Read( stream );
	m_SaveFile.Vehicles.Read( stream );
	m_SaveFile.Objects.Read( stream );
	m_SaveFile.PathFinding.Read( stream );
	m_SaveFile.Cranes.Read( stream );
	m_SaveFile.Pickups.Read( stream );
	m_SaveFile.Phones.Read( stream );
	m_SaveFile.Restarts.Read( stream );
	m_SaveFile.RadarBlips.Read( stream );
	m_SaveFile.TheZones.Read( stream );
	m_SaveFile.Gangs.Read( stream );
	m_SaveFile.CarGenerators.Read( stream );
	m_SaveFile.Particles.Read( stream );
	m_SaveFile.AudioScriptObjects.Read( stream );
	m_SaveFile.PlayerInfo.Read( stream );
	m_SaveFile.PlayerStats.Read( stream );
	m_SaveFile.StreamingData.Read( stream );
	m_SaveFile.PedTypeInfos.Read( stream );

	stream.close();

	return true;
}
void FSaveFile::Write( const std::filesystem::path& rPath )
{
	std::ofstream fout( rPath, std::ios::binary | std::ios::trunc );

	FBufferHelpers::WriteObject( 26456u, fout );
	FBufferHelpers::WriteObject( m_SaveFile.SimpleData, fout );

	m_SaveFile.TheScriptsData.Write( fout );
	m_SaveFile.PlayerPedsData.Write( fout );
	m_SaveFile.Garages.Write( fout );
	m_SaveFile.Vehicles.Write( fout );
	m_SaveFile.Objects.Write( fout );
	m_SaveFile.PathFinding.Write( fout );
	m_SaveFile.Cranes.Write( fout );
	m_SaveFile.Pickups.Write( fout );
	m_SaveFile.Phones.Write( fout );
	m_SaveFile.Restarts.Write( fout );
	m_SaveFile.RadarBlips.Write( fout );
	m_SaveFile.TheZones.Write( fout );
	m_SaveFile.Gangs.Write( fout );
	m_SaveFile.CarGenerators.Write( fout );
	m_SaveFile.Particles.Write( fout );
	m_SaveFile.AudioScriptObjects.Write( fout );
	m_SaveFile.PlayerInfo.Write( fout );
	m_SaveFile.PlayerStats.Write( fout );
	m_SaveFile.StreamingData.Write( fout );
	m_SaveFile.PedTypeInfos.Write( fout );

	fout.close();
}
