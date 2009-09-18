#ifndef __element_h__
#define __element_h__

#include "libxmljs.h"
#include "node.h"

#include <libxml/xpath.h>
#include <libxml/xmlstring.h>

namespace libxmljs {

#define UNWRAP_ELEMENT(from)                              \
  Element *element = ObjectWrap::Unwrap<Element>(from);   \
  assert(element);


#define NAME_SYMBOL     String::NewSymbol("name")
#define CONTENT_SYMBOL  String::NewSymbol("content")

class Element : public Node {
public:
  Element(
    xmlNode* node);

  virtual ~Element();

  static void
  Initialize(
    v8::Handle<v8::Object> target);

  static v8::Handle<v8::Value>
  New(
    const v8::Arguments& args);

  static v8::Handle<v8::Value>
  GetProperty(
    v8::Local<v8::String> property,
    const v8::AccessorInfo& info);

  static void
  SetProperty(
    v8::Local<v8::String> property,
    v8::Local<v8::Value> value,
    const v8::AccessorInfo& info);

  static v8::Handle<v8::Value>
  Attr(
    const v8::Arguments& args);

  static v8::Handle<v8::Value>
  AddChild(
    const v8::Arguments& args);

  static v8::Handle<v8::Value>
  Find(
    const v8::Arguments& args);

  static v8::Handle<v8::Value>
  Text(
    const v8::Arguments& args);

  void
  set_name(
    const char * name);

  const char *
  get_name();

  v8::Handle<v8::Value>
  get_attr(
    const char * name);

  void
  set_attr(
    const char * name,
    const char * value);

  void
  add_child(
    Element * child);

  void
  set_content(
    const char * content);

  v8::Handle<v8::Value>
  get_content();

  v8::Handle<v8::Value>
  find(
    const char * xpath);

};

} // namespace libxmljs

#endif // __element_h__