#include <string>
#include <iostream>
#include "fontconfig/fontconfig.h"

const std::string SearchFont(FcConfig* conf, FcPattern* pattern) {
    FcResult result;
    FcPattern* fontPattern = FcFontMatch(conf, pattern, &result);
    if(!fontPattern) {
        return "";
    }

    if(result != FcResult::FcResultMatch) {
        FcPatternDestroy(fontPattern);
        return "";
    }

    FcChar8* filePaht;
	FcPatternGetString(fontPattern, FC_FILE, 0, &filePaht);
    const std::string foundPath = (char*)filePaht;
    FcPatternDestroy(fontPattern);
    return foundPath;
};

int main(int argc, char* argv[]) {
    if(argc <= 1) {
        printf("usage: %s \"font-name\"\n", argv[0]);
        return 0;
    }

    FcInit();

    FcPattern* searchPattern = FcPatternCreate();
    if(!FcPatternAddString(searchPattern, FC_FAMILY, (const FcChar8*)argv[1])) {
        return 1;
    }

    FcConfig* configure = FcInitLoadConfigAndFonts();
    FcConfigSubstitute(configure, searchPattern, FcMatchPattern);
    FcDefaultSubstitute(searchPattern);

    const std::string path = SearchFont(configure, searchPattern);
    if(!path.empty()) {
        std::cout << "found font path: " << path << std::endl;
    }

    FcPatternDestroy(searchPattern);
    FcConfigDestroy(configure);

    FcFini();
    return 0;
}