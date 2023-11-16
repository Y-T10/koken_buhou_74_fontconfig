#include <cstdio>
#include "fontconfig/fontconfig.h"

int main(int argc, char* argv[]) {
    if(argc <= 1) {
        printf("usage: %s \"font-name\"\n", argv[0]);
        return 0;
    }

    FcInit();

    FcPattern* searchPattern = FcPatternCreate();
    FcPatternAddString(searchPattern, FC_FAMILY, (const FcChar8*)argv[1]);

    FcConfig* configure = FcInitLoadConfigAndFonts();
    FcConfigSubstitute(configure, searchPattern, FcMatchPattern);
    FcDefaultSubstitute(searchPattern);

    FcChar8* filePaht;
    FcResult result;
    FcPattern* fontPattern = FcFontMatch(configure, searchPattern, &result);
	FcPatternGetString(fontPattern, FC_FILE, 0, &filePaht);
	printf("found font path: %s\n", filePaht);

    FcPatternDestroy(fontPattern);
    FcPatternDestroy(searchPattern);
    FcConfigDestroy(configure);

    FcFini();
    return 0;
}