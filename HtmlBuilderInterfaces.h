#ifndef HTML_BUILDER_INTERFACES_H
#define HTML_BUILDER_INTERFACES_H

#include <string>

enum class TagType
{
    meta,
    class_tag
};

class IHtmlTagBuilder
{
public:
    virtual ~IHtmlTagBuilder() = default;
    virtual void setTagType(std::string tag_type) = 0;
    virtual void setClassTag(std::string tag_type, std::string class_name) = 0;
    virtual void addTagContents(std::string tag_contents) = 0;
    virtual void addMetaData(std::string key, std::string value) = 0;
    virtual void addEmbeddedTag(IHtmlTagBuilder* tag) = 0;
    virtual std::string buildTag() = 0;
};

class IHtmlDocBuilder
{
public:
    virtual ~IHtmlDocBuilder() = default;
    virtual void addDocument(IHtmlTagBuilder* document) = 0;
    virtual void buildDocument() = 0;
};

#endif