#include "sppch.h"
#include "Particles.h"

#include "Core/BufferHelpers.h"

bool FParticles::Read( std::ifstream& rStream )
{
	FBufferHelpers::Skip8( rStream );
	
	FBufferHelpers::ReadObject( NumPariclesObjects, rStream );

	Particles.resize( NumPariclesObjects + 1 );

	for( auto& rParticles : Particles )
	{
		FBufferHelpers::ReadObject( rParticles.pvtbl, rStream );

		FBufferHelpers::ReadObject( rParticles.Matrix.Right, rStream );
		FBufferHelpers::ReadObject( rParticles.Matrix.flags, rStream );

		FBufferHelpers::ReadObject( rParticles.Matrix.Up, rStream );
		FBufferHelpers::ReadObject( rParticles.Matrix.pad, rStream );

		FBufferHelpers::ReadObject( rParticles.Matrix.At, rStream );
		FBufferHelpers::ReadObject( rParticles.Matrix.pad1, rStream );

		FBufferHelpers::ReadObject( rParticles.Matrix.Position, rStream );
		FBufferHelpers::ReadObject( rParticles.Matrix.pad2, rStream );

		FBufferHelpers::ReadObject( rParticles.Matrix.pAttachment, rStream );
		FBufferHelpers::ReadObject( rParticles.Matrix.HasRwMatrix, rStream );

		FBufferHelpers::SkipN( rStream, 3 );

		FBufferHelpers::ReadObject( rParticles.pNext, rStream );
		FBufferHelpers::ReadObject( rParticles.pPrev, rStream );
		FBufferHelpers::ReadObject( rParticles.pParticle, rStream );
		FBufferHelpers::ReadObject( rParticles.RemoveTimer, rStream );
		FBufferHelpers::ReadObject( rParticles.ParticleObjectType, rStream );
		FBufferHelpers::ReadObject( rParticles.ParticleType, rStream );
		
		
		FBufferHelpers::ReadObject( rParticles.NumEffectCycles, rStream );
		FBufferHelpers::ReadObject( rParticles.SkipFrames, rStream );
		FBufferHelpers::Skip2( rStream );
		
		FBufferHelpers::ReadObject( rParticles.FrameCounter, rStream );
		FBufferHelpers::ReadObject( rParticles.State, rStream );
		FBufferHelpers::ReadObject( rParticles.Target, rStream );
		FBufferHelpers::ReadObject( rParticles.Spread, rStream );
		FBufferHelpers::ReadObject( rParticles.Size, rStream );
		FBufferHelpers::ReadObject( rParticles.Color, rStream );
		FBufferHelpers::ReadObject( rParticles.DestroyWhenFar, rStream );
		FBufferHelpers::ReadObject( rParticles.CreationChance, rStream );

		FBufferHelpers::Skip2( rStream );
	}

	return true;
}

void FParticles::Write( std::ofstream& rStream )
{
	FBufferHelpers::WriteObject( 7896u, rStream );
	FBufferHelpers::WriteObject( 7892u, rStream );

	FBufferHelpers::WriteObject( NumPariclesObjects, rStream );

	for( auto& rParticles : Particles )
	{
		FBufferHelpers::WriteObject( rParticles.pvtbl, rStream );

		FBufferHelpers::WriteObject( rParticles.Matrix.Right, rStream );
		FBufferHelpers::WriteObject( rParticles.Matrix.flags, rStream );

		FBufferHelpers::WriteObject( rParticles.Matrix.Up, rStream );
		FBufferHelpers::WriteObject( rParticles.Matrix.pad, rStream );

		FBufferHelpers::WriteObject( rParticles.Matrix.At, rStream );
		FBufferHelpers::WriteObject( rParticles.Matrix.pad1, rStream );

		FBufferHelpers::WriteObject( rParticles.Matrix.Position, rStream );
		FBufferHelpers::WriteObject( rParticles.Matrix.pad2, rStream );

		FBufferHelpers::WriteObject( rParticles.Matrix.pAttachment, rStream );
		FBufferHelpers::WriteObject( rParticles.Matrix.HasRwMatrix, rStream );

		FBufferHelpers::WriteN( rStream, 3 );

		FBufferHelpers::WriteObject( rParticles.pNext, rStream );
		FBufferHelpers::WriteObject( rParticles.pPrev, rStream );
		FBufferHelpers::WriteObject( rParticles.pParticle, rStream );
		FBufferHelpers::WriteObject( rParticles.RemoveTimer, rStream );
		FBufferHelpers::WriteObject( rParticles.ParticleObjectType, rStream );
		FBufferHelpers::WriteObject( rParticles.ParticleType, rStream );


		FBufferHelpers::WriteObject( rParticles.NumEffectCycles, rStream );
		FBufferHelpers::WriteObject( rParticles.SkipFrames, rStream );
		FBufferHelpers::WriteN( rStream, 2 );

		FBufferHelpers::WriteObject( rParticles.FrameCounter, rStream );
		FBufferHelpers::WriteObject( rParticles.State, rStream );
		FBufferHelpers::WriteObject( rParticles.Target, rStream );
		FBufferHelpers::WriteObject( rParticles.Spread, rStream );
		FBufferHelpers::WriteObject( rParticles.Size, rStream );
		FBufferHelpers::WriteObject( rParticles.Color, rStream );
		FBufferHelpers::WriteObject( rParticles.DestroyWhenFar, rStream );
		FBufferHelpers::WriteObject( rParticles.CreationChance, rStream );

		FBufferHelpers::WriteN( rStream, 2 );
	}

}
