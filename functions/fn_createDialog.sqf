/*
Description:
	Creates (opens) the PGR dialog.
*/

if (!isNull findDisplay 11111) exitWith {
	["The PGR dialog is already open."] call BIS_fnc_error;
};

//Create the dialog:
createDialog "PGR_Dialog";

disableSerialization;

private _contentCtrl = findDisplay 11111 displayCtrl 101;
private _filterCtrl = findDisplay 11111 displayCtrl 100;

//Add columns (the first one already exists):
{
	_x lnbAddColumn 0.33;
	_x lnbAddColumn 0.66;
} forEach [_contentCtrl, _filterCtrl];

_filterCtrl lnbAddRow ["Name", "Group", "Role"];

{
	_contentCtrl lnbAddRow [name _x, groupId group _x, roleDescription _x];
} forEach allUnits;

[_filterCtrl, _contentCtrl] call BIS_fnc_initListNBoxSorting;