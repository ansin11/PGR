/*
Description:
	Initializes and populates the PGR_Filter and PGR_Content controls when the PGR dialog is created.
Parameters:
	_parentDisplay: DISPLAY
*/

disableSerialization;

params ["_parentDisplay"];

private _contentCtrl = _parentDisplay displayCtrl 101;
private _filterCtrl = _parentDisplay displayCtrl 100;

//Add columns (the first one already exists):
{
	_x lnbAddColumn 0.33;
	_x lnbAddColumn 0.66;
} forEach [_contentCtrl, _filterCtrl];

_filterCtrl lnbAddRow ["Name", "Group", "Role"];

//Add rows with player information:
{
	_contentCtrl lnbAddRow [name _x, groupId group _x, roleDescription _x];
	_contentCtrl lnbSetPicture [[_forEachIndex, 0], getText (configFile >> "CfgRanks" >> str rankId _x >> "texture")];
} forEach allPlayers;

[_filterCtrl, _contentCtrl] call BIS_fnc_initListNBoxSorting;

ctrlSetFocus _contentCtrl;