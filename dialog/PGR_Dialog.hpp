#define GUI_BACKGROUND_COLOR {"(profileNamespace getVariable ['GUI_BCG_RGB_R', 0.13])", "(profileNamespace getVariable ['GUI_BCG_RGB_G', 0.54])", "(profileNamespace getVariable ['GUI_BCG_RGB_B', 0.21])", "(profileNamespace getVariable ['GUI_BCG_RGB_A', 0.8])"}

class PGR_Dialog {
	idd = 11111;
	enableSimulation = true;
	
	class Controls {
		class PGR_DialogTitleBar {
			idc = -1;
			moving = true; //Toggles possibility to drag the dialog across the screen.
			type = CT_STATIC;
			style = ST_LEFT;
			shadow = 0;
			colorBackground[] = GUI_BACKGROUND_COLOR;
			colorText[] = {1, 1, 1, 1};
			font = "PuristaMedium";
			sizeEx = GUI_TEXT_SIZE_MEDIUM;
			text = "Active Protection System";
			x = 0;
			y = 0;
			w = 1;
			h = 0.04;
		};
		
		class PGR_DialogBackground {
			idc = -1;
			type = CT_STATIC;
			style = ST_CENTER;
			colorBackground[] = {0, 0, 0, 0.6};
			colorText[] = {1, 1, 1, 1};
			font = "RobotoCondensed";
			sizeEx = GUI_TEXT_SIZE_MEDIUM;
			text = "";
			shadow = 0;
			x = 0;
			y = 0.045;
			w = 1;
			h = 0.91;
		};
		
		class PGR_TargetControlsGroup {
			idc = 100;
			type = CT_CONTROLS_GROUP;
			style = ST_MULTI;
			shadow = 0;
			x = 0;
			y = 0.045;
			w = 1;
			h = 0.91;
			
			class VScrollbar {
				color[] = {1, 1, 1, 1};
				colorActive[] = {1, 1, 1, 1};
				colorDisabled[] = {1, 1, 1, 1};
				thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
				arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
				arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
				border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
				shadow = 0;
				scrollSpeed = 0.06;
				width = 0.019;
				autoScrollEnabled = 0;
			};
			
			class HScrollbar {};
			
			class Controls {};
		};

		class PGR_DialogButtonClose: RscShortcutButton {
			idc = -1;
			type = CT_SHORTCUTBUTTON;
			style = ST_CENTER + ST_FRAME + ST_HUD_BACKGROUND;
			action = "closeDialog 0;";
			shadow = 0;
			animTextureNormal = "#(argb,8,8,3)color(1,1,1,1)";
			animTextureDisabled = "#(argb,8,8,3)color(1,1,1,1)";
			animTextureOver = "#(argb,8,8,3)color(1,1,1,1)";
			animTextureFocused = "#(argb,8,8,3)color(1,1,1,1)";
			animTexturePressed = "#(argb,8,8,3)color(1,1,1,1)";
			animTextureDefault = "#(argb,8,8,3)color(1,1,1,1)";
			colorBackground[] = {0, 0, 0, 0.8};
			colorBackgroundFocused[] = {1, 1, 1, 1};
			colorBackground2[] = {0.75, 0.75, 0.75, 1};
			color[] = {1, 1, 1, 1};
			colorFocused[] = {0, 0, 0, 1};
			color2[] = {0, 0, 0, 1};
			colorText[] = {1, 1, 1, 1};
			colorDisabled[] = {1, 1, 1, 0.25};
			text = "CLOSE";
			textSecondary = "";
			colorSecondary[] = {1, 1, 1, 1};
			colorFocusedSecondary[] = {0, 0, 0, 1};
			color2Secondary[] = {0, 0, 0, 1};
			colorDisabledSecondary[] = {1, 1, 1, 0.25};
			sizeExSecondary = GUI_TEXT_SIZE_MEDIUM;
			fontSecondary = "PuristaLight";
			period = 1.2;
			periodFocus = 1.2;
			periodOver = 1.2;
			size = GUI_TEXT_SIZE_MEDIUM;
			sizeEx = GUI_TEXT_SIZE_MEDIUM;
			tooltipColorText[] = {1, 1, 1, 1};
			tooltipColorBox[] = {1, 1, 1, 1};
			tooltipColorShade[] = {0, 0, 0, 0.65};
			soundEnter[] = {"\A3\ui_f\data\sound\RscButtonMenu\soundEnter", 0.09, 1};
			soundPush[] = {"\A3\ui_f\data\sound\RscButtonMenu\soundPush", 0.09, 1};
			soundClick[] = {"\A3\ui_f\data\sound\RscButtonMenu\soundClick", 0.09, 1};
			soundEscape[] = {"\A3\ui_f\data\sound\RscButtonMenu\soundEscape", 0.09, 1};
			x = 0.875;
			y = 0.96;
			w = 0.125;
			h = 0.04;

			class TextPos {
				left = 0.25 * GUI_GRID_W;
				top = (GUI_GRID_H - GUI_TEXT_SIZE_MEDIUM) / 2;
				right = 0.005;
				bottom = 0;
			};

			class Attributes {
				font = "PuristaLight";
				color = "#E5E5E5";
				align = "left";
				shadow = "false";
			};

			class ShortcutPos {
				left = 5.25 * GUI_GRID_W;
				top = 0;
				w = 1 * GUI_GRID_W;
				h = 1 * GUI_GRID_H;
			};
		};
	};
};