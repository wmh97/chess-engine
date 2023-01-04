
#include "HtmlTagBuilder.h"

#include <iostream>

void HtmlTagBuilder::setTagType(std::string tag_type)
{
    _tag_type = tag_type;
    _contents = "<" + _tag_type + ">"; 
    _write_pos = _contents.size();
    _contents += "</" + _tag_type + ">";
}

void HtmlTagBuilder::setClassTag(std::string tag_type, std::string class_name)
{
    _tag_type = tag_type;
    _contents = "<" + tag_type + " class=\"" + class_name + "\"" + ">"; 
    _write_pos = _contents.size();
    _contents += "</" + _tag_type + ">";
}

void HtmlTagBuilder::addTagContents(std::string tag_contents)
{
    _contents.insert(_write_pos, tag_contents);
    _write_pos += tag_contents.size();
}

void HtmlTagBuilder::addMetaData(std::string key, std::string value)
{
    std::string data {"<meta " + key + "=\"" + value + "\"" + ">"};
    _contents.insert(_write_pos, data);
    _write_pos += data.size();
}

void HtmlTagBuilder::addEmbeddedTag(IHtmlTagBuilder* tag)
{
    _components.push_back(tag);
}

std::string HtmlTagBuilder::buildTag()
{
    if (_components.size() > 0)
    {
        for (const auto& c : _components)
        {
            auto to_insert = c->buildTag();
            _contents.insert(_write_pos, to_insert);
            _write_pos += to_insert.size();
        }
    }
    return _contents;
}

