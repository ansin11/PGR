/*
Description:
	Creates (opens) the PGR dialog.
*/

if (!isNull findDisplay 11111) exitWith {
	["The PGR dialog is already open."] call BIS_fnc_error;
};

//Create the dialog:
createDialog ["PGR_Dialog", true];
