/*
Description:
	Creates (opens) the PGR dialog.
*/

with uiNamespace do {
	if (!isNull PGR_dialogDisplay) exitWith {
		["The PGR dialog is already open."] call BIS_fnc_error;
	};

	//Create the dialog:
	PGR_dialogDisplay = createDialog ["PGR_Dialog", true];
};
