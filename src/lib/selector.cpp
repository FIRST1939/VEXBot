#include "main.h"
#include "selector.h"

const char *buttonMap[] = {"Drive Square", "Do Nothing", "\n", "\n", "", "", "", "", ""};
AutonomousMode selected_autonomous = DO_NOTHING;

lv_res_t redButtonAction (lv_obj_t *button, const char *text) {

    lv_theme_t *theme = lv_theme_nemo_init(0, NULL);
	lv_theme_set_current(theme);

	if (strcmp(txt, "Drive Square") == 0) { selected_autonomous = DRIVE_SQUARE; }
	if (strcmp(txt, "Do Nothing") == 0) { selected_autonomous = DO_NOTHING; }
	return LV_RES_OK;
}

lv_res_t blueButtonAction (lv_obj_t *button, const char *text) {

    lv_theme_t *theme = lv_theme_nemo_init(230, NULL);
	lv_theme_set_current(theme);

	if (strcmp(txt, "Drive Square") == 0) { selected_autonomous = DRIVE_SQUARE; }
	if (strcmp(txt, "Do Nothing") == 0) { selected_autonomous = DO_NOTHING; }
	return LV_RES_OK;
}

lv_res_t skillsButtonAction (lv_obj_t *button) {

    lv_theme_t *theme = lv_theme_nemo_init(60, NULL);
	lv_theme_set_current(theme);

	lv_style_scr.body.main_color = LV_COLOR_BLACK; 
	selected_autonomous = SKILLS;
	return LV_RES_OK;
}

void initializeSelector () {

	lv_theme_t *theme = lv_theme_nemo_init(148, NULL);
	lv_theme_set_current(theme);

	lv_obj_t *tabview;
	tabview = lv_tabview_create(lv_scr_act(), NULL);

	lv_obj_t *redTab = lv_tabview_add_tab(tabview, "Red");
	lv_obj_t *blueTab = lv_tabview_add_tab(tabview, "Blue");
	lv_obj_t *skillsTab = lv_tabview_add_tab(tabview, "Skills");

	lv_obj_t *redButton = lv_btnm_create(redTab, NULL);
	lv_btnm_set_map(redButton, buttonMap);
	lv_btnm_set_action(redButton, redButtonAction);
	lv_btnm_set_toggle(redButton, true, 3);
	lv_obj_set_size(redButton, 450, 130);
	lv_obj_set_pos(redButton, 0, 100);
	lv_obj_align(redButton, NULL, LV_ALIGN_CENTER, 0, 0);

	lv_obj_t *blueButton = lv_btnm_create(blueTab, NULL);
	lv_btnm_set_map(blueButton, buttonMap);
	lv_btnm_set_action(blueButton, blueButtonAction);
	lv_btnm_set_toggle(blueButton, true, 3);
	lv_obj_set_size(blueButton, 450, 130);
	lv_obj_set_pos(blueButton, 0, 100);
	lv_obj_align(blueButton, NULL, LV_ALIGN_CENTER, 0, 0);

	lv_obj_t *skillsButton = lv_btn_create(skillsTab, NULL);
	lv_obj_t *label = lv_label_create(skillsButton, NULL);
	lv_label_set_text(label, "Skills");
	lv_btn_set_action(skillsButton, LV_BTN_ACTION_CLICK, skillsButtonAction);
	lv_obj_set_size(skillsButton, 450, 50);
	lv_obj_set_pos(skillsButton, 0, 100);
	lv_obj_align(skillsButton, NULL, LV_ALIGN_CENTER, 0, 0);
}
