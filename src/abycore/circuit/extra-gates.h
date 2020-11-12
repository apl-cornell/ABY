#ifndef __EXTRA_GATES_H__
#define __EXTRA_GATES_H__

#include <vector>

#include "circuit.h"
#include "share.h"

extern std::vector<int> int32div_circuit;

share* PutInt32DIVGate(Circuit* circuit, share* lhs, share* rhs);

share* PutMinGate(Circuit* circuit, share* lhs, share* rhs);

share* PutMaxGate(Circuit* circuit, share* lhs, share* rhs);

#endif
