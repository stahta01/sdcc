bool m6809notUsed(const char *what, lineNode *endPl, lineNode *head);
bool m6809notUsedFrom(const char *what, const char *label, lineNode *head);
bool m6809canAssign (const char *dst, const char *src, const char *exotic);
int m6809instructionSize(lineNode *node);

