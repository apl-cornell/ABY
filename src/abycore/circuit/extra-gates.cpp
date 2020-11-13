#include <vector>

#include "booleancircuits.h"
#include "circuit.h"
#include "share.h"
#include "extra-gates.h"

share* PutInt32DIVGate(Circuit* circ, share* lhs, share* rhs) {
  BooleanCircuit* bcirc = (BooleanCircuit*)circ;
  std::vector<uint32_t> div_input;
  div_input.insert(div_input.end(), rhs->get_wires().begin(), rhs->get_wires().end());
  div_input.insert(div_input.end(), lhs->get_wires().begin(), lhs->get_wires().end());

  std::vector<uint32_t> div_output = bcirc->PutGateFromArray(int32div_circuit, div_input);

  // for some reason the int32 div circuit has 33 output gates;
  // remove the last one
  div_output.pop_back();
  div_input.clear();

	return new boolshare(div_output, bcirc);
}

share* PutMinGate(Circuit* circ, share* lhs, share* rhs) {
  BooleanCircuit* bcirc = (BooleanCircuit*)circ;
	std::vector<std::vector<uint32_t> > min(2);
  min[0] = lhs->get_wires();
  min[1] = rhs->get_wires();
	return new boolshare(bcirc->PutMinGate(min), bcirc);
}

share* PutMaxGate(Circuit* circ, share* lhs, share* rhs) {
  BooleanCircuit* bcirc = (BooleanCircuit*)circ;
	std::vector<std::vector<uint32_t> > max(2);
  max[0] = lhs->get_wires();
  max[1] = rhs->get_wires();
	return new boolshare(bcirc->PutMaxGate(max), bcirc);
}

