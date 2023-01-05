#ifndef HTML_TAG_BUILDER_H
#define HTML_TAG_BUILDER_h

#include "HtmlBuilderInterfaces.h"

#include <vector>

class HtmlTagBuilder : public IHtmlTagBuilder
{
public:
    HtmlTagBuilder() = default;
    void setTagType(std::string tag_type) override;
    void setClassTag(std::string tag_type, std::string class_name) override;
    void addTagContents(std::string tag_contents) override;
    void addMetaData(std::string key, std::string value) override;
    void addEmbeddedTag(std::unique_ptr<IHtmlTagBuilder> tag) override;
    std::string buildTag() override;
private:
    std::string _tag_type {};
    std::string _contents {};
    size_t _write_pos {0};
    int _indentation_level {0};
    std::vector<std::unique_ptr<IHtmlTagBuilder>> _components {};
};

#endif