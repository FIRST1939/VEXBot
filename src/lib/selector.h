enum AutonomousMode {DRIVE_SQUARE, DO_NOTHING, SKILLS};

extern const char *buttonMap[];
extern AutonomousMode selected_autonomous;

lv_res_t redButtonAction (lv_obj_t *button, const char *text);
lv_res_t blueButtonAction (lv_obj_t *button, const char *text);
lv_res_t skillsButtonAction (lv_obj_t *button);
void initializeSelector();
