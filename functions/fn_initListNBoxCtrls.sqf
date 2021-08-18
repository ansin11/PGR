/*
Description:
	Initializes and populates the PGR_Filter and PGR_Content controls when the PGR dialog is created.
Parameters:
	_parentDisplay: DISPLAY
*/

disableSerialization;

params ["_parentDisplay"];

private _filterCtrl = _parentDisplay displayCtrl 100;
private _contentCtrl = _parentDisplay displayCtrl 101;

//Add columns (the first one already exists):
{
	_x lnbAddColumn 0.33;
	_x lnbAddColumn 0.66;
} forEach [_filterCtrl, _contentCtrl];

//Add column headers:
_filterCtrl lnbAddRow ["Name", "Group", "Role"];

//Add rows with player information:
{
	_contentCtrl lnbAddRow [name _x, groupId group _x, roleDescription _x];
	_contentCtrl lnbSetPicture [[_forEachIndex, 0], getText (configFile >> "CfgRanks" >> str rankId _x >> "texture")];
	_contentCtrl lnbSetPicture [[_forEachIndex, 1], [side group _x] call PGR_fnc_getSidePicture];
	_contentCtrl lnbSetPictureColor [[_forEachIndex, 1], [side group _x] call BIS_fnc_sideColor];
} forEach allUnits; (allPlayers select {!(_x isKindOf "VirtualMan_F")}); //The select-statement removes Headless Clients, Virtual Spectators and Virtual Curators.

[_filterCtrl, _contentCtrl] call BIS_fnc_initListNBoxSorting;

ctrlSetFocus _contentCtrl;