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
