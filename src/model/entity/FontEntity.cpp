#include "FontEntity.h"

FontEntity::FontEntity(){

}

FontEntity::FontEntity(std::string strFontName, std::string strFontPath){
    mStrFontName = strFontName;
    mStrFontPath = strFontPath;
}

void FontEntity::setStrFontName(std::string strFontName){
    mStrFontName = strFontName;
}
std::string FontEntity::getStrFontName() const{
    return mStrFontName;
}

void FontEntity::setStrFontPath(std::string strFontPath){
    mStrFontPath = strFontPath;
}
std::string FontEntity::getStrFontPath() const{
    return mStrFontPath;
}
void FontEntity::setNumFileSize(int numFileSize){
    mNumFileSize = numFileSize;
}
int FontEntity::getNumFileSize() const{
    return mNumFileSize;
}

void FontEntity::setCharFontFileData(unsigned char *charFontFileData){
    mCharFontFileData = charFontFileData;
}
unsigned char * FontEntity::getCharFontFileData() const{
    return mCharFontFileData;
}