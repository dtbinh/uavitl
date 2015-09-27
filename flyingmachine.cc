#include "sim.hh"
#include "flyingmachine.hh"
#include "gnc.hh"

Flyingmachine::Flyingmachine(Sim sim, GNC gnc):
    _sim(sim),
    _gnc(gnc)
{
}

Flyingmachine::~Flyingmachine()
{
}

int Flyingmachine::readFromSim()
{
    _sim.readDatagram();
    return 0;
}
