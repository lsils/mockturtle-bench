#include <benchmark/benchmark.h>

#include <iostream>

#include <aig/gia/gia.h>
#include <base/wlc/wlc.h>

#include <fmt/format.h>

namespace abc
{
void Gia_StoComputeCuts( Gia_Man_t * pGia );
void Wlc_BlastFullAdder( Gia_Man_t* pNew, int a, int b, int c, int* pc, int* ps );
void Wlc_BlastAdder( Gia_Man_t* pNew, int* pAdd0, int* pAdd1, int nBits, int Carry );
void Gia_ManComputeDomsTry( Gia_Man_t * p );
} // namespace abc

void BM_cut_enumeration( benchmark::State& state )
{
  for ( auto _ : state )
  {
    state.PauseTiming();
    auto gia = abc::Gia_AigerRead( fmt::format( "{}/c432.aig", NETWORKS_PATH ).c_str(), 0, 0, 0 );
    state.ResumeTiming();

    abc::Gia_StoComputeCuts( gia );

    state.PauseTiming();
    abc::Gia_ManHashStop( gia );
    abc::Gia_ManStop( gia );
    state.ResumeTiming();
  }
}

BENCHMARK( BM_cut_enumeration );
BENCHMARK_MAIN();
