#include "main.h"
#include "selector.h"

const char *btnmMap[] = {"Drive Square", "Do Nothing", "\n", "\n", "", "", "", "", ""};
AutonomousMode selected_autonomous = DO_NOTHING;

lv_res_t redBtnmAction (lv_obj_t *btnm, const char *txt) {

    lv_theme_t *th = lv_theme_nemo_init(0, NULL);
	lv_theme_set_current(th);

	if (strcmp(txt, "Drive Square") == 0) { selected_autonomous = DRIVE_SQUARE; }
	if (strcmp(txt, "Do Nothing") == 0) { selected_autonomous = DO_NOTHING; }
	return LV_RES_OK;
}

lv_res_t blueBtnmAction (lv_obj_t *btnm, const char *txt) {

    lv_theme_t *th = lv_theme_nemo_init(230, NULL);
	lv_theme_set_current(th);

	if (strcmp(txt, "Drive Square") == 0) { selected_autonomous = DRIVE_SQUARE; }
	if (strcmp(txt, "Do Nothing") == 0) { selected_autonomous = DO_NOTHING; }
	return LV_RES_OK;
}

lv_res_t skillsBtnAction (lv_obj_t *btn) {

    lv_theme_t *th = lv_theme_nemo_init(60, NULL);
	lv_theme_set_current(th);

	lv_style_scr.body.main_color = LV_COLOR_BLACK; 
	selected_autonomous = SKILLS;
	return LV_RES_OK;
}

void initializeSelector () {

	lv_theme_t *th = lv_theme_nemo_init(148, NULL);
	lv_theme_set_current(th);

	lv_obj_t *tabview;
	tabview = lv_tabview_create(lv_scr_act(), NULL);

	lv_obj_t *redTab = lv_tabview_add_tab(tabview, "Red");
	lv_obj_t *blueTab = lv_tabview_add_tab(tabview, "Blue");
	lv_obj_t *skillsTab = lv_tabview_add_tab(tabview, "Skills");

	lv_obj_t *redBtnm = lv_btnm_create(redTab, NULL);
	lv_btnm_set_map(redBtnm, btnmMap);
	lv_btnm_set_action(redBtnm, redBtnmAction);
	lv_btnm_set_toggle(redBtnm, true, 3);
	lv_obj_set_size(redBtnm, 450, 130);
	lv_obj_set_pos(redBtnm, 0, 100);
	lv_obj_align(redBtnm, NULL, LV_ALIGN_CENTER, 0, 0);

	lv_obj_t *blueBtnm = lv_btnm_create(blueTab, NULL);
	lv_btnm_set_map(blueBtnm, btnmMap);
	lv_btnm_set_action(blueBtnm, blueBtnmAction);
	lv_btnm_set_toggle(blueBtnm, true, 3);
	lv_obj_set_size(blueBtnm, 450, 130);
	lv_obj_set_pos(blueBtnm, 0, 100);
	lv_obj_align(blueBtnm, NULL, LV_ALIGN_CENTER, 0, 0);

	lv_obj_t *skillsBtn = lv_btn_create(skillsTab, NULL);
	lv_obj_t *label = lv_label_create(skillsBtn, NULL);
	lv_label_set_text(label, "Skills");
	lv_btn_set_action(skillsBtn, LV_BTN_ACTION_CLICK, skillsBtnAction);
	lv_obj_set_size(skillsBtn, 450, 50);
	lv_obj_set_pos(skillsBtn, 0, 100);
	lv_obj_align(skillsBtn, NULL, LV_ALIGN_CENTER, 0, 0);
}
