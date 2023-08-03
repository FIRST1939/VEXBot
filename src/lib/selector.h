enum AutonomousMode {DRIVE_SQUARE, DO_NOTHING, SKILLS};

extern const char *btnmMap[];
extern AutonomousMode selected_autonomous;

lv_res_t redBtnmAction (lv_obj_t *btnm, const char *txt);
lv_res_t blueBtnmAction (lv_obj_t *btnm, const char *txt);
lv_res_t skillsBtnAction (lv_obj_t *btn);
void initializeSelector();
