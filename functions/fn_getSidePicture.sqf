/*
Description:
	Returns the texture path to the side icon of the given side.
Parameters:
	_side: SIDE
Return Value: STRING
*/

params ["_side"];

switch (_side) do {
	case civilian: { "\A3\ui_f\data\map\markers\nato\c_unknown.paa" };
	case east: { "\A3\ui_f\data\map\markers\nato\o_unknown.paa" };
	case independent: { "\A3\ui_f\data\map\markers\nato\n_unknown.paa" };
	case west: { "\A3\ui_f\data\map\markers\nato\b_unknown.paa" };
};