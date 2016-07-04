// Generated by gtkmmproc -- DO NOT MODIFY!


#include <goocanvasmm/image.h>
#include <goocanvasmm/private/image_p.h>

/* Copyright (C) 1998-2006 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */


#include <goocanvasimage.h>


namespace Goocanvas
{

Image::Image(const Glib::RefPtr<Gdk::Pixbuf>& pixbuf, double x, double y)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Goocanvas::ItemSimple(Glib::ConstructParams(image_class_.init(), "pixbuf",pixbuf->gobj(),"x",x,"y",y, static_cast<char*>(0)))
{
}

Image::Image( double x, double y)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Goocanvas::ItemSimple(Glib::ConstructParams(image_class_.init(), "x",x,"y",y, static_cast<char*>(0)))
{
}

} //namspace Goocanvas


namespace
{
} // anonymous namespace


namespace Glib
{

Glib::RefPtr<Goocanvas::Image> wrap(GooCanvasImage* object, bool take_copy)
{
  return Glib::RefPtr<Goocanvas::Image>( dynamic_cast<Goocanvas::Image*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Goocanvas
{


/* The *_Class implementation: */

const Glib::Class& Image_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Image_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(goo_canvas_image_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void Image_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* Image_Class::wrap_new(GObject* object)
{
  return new Image((GooCanvasImage*)object);
}


/* The implementation: */

GooCanvasImage* Image::gobj_copy()
{
  reference();
  return gobj();
}

Image::Image(const Glib::ConstructParams& construct_params)
:
  Goocanvas::ItemSimple(construct_params)
{

}

Image::Image(GooCanvasImage* castitem)
:
  Goocanvas::ItemSimple((GooCanvasItemSimple*)(castitem))
{}


Image::~Image()
{}


Image::CppClassType Image::image_class_; // initialize static member

GType Image::get_type()
{
  return image_class_.init().get_type();
}


GType Image::get_base_type()
{
  return goo_canvas_image_get_type();
}


Glib::RefPtr<Image> Image::create(double x, double y)
{
  return Glib::RefPtr<Image>( new Image(x, y) );
}
Glib::RefPtr<Image> Image::create(const Glib::RefPtr<Gdk::Pixbuf>& pixbuf, double x, double y)
{
  return Glib::RefPtr<Image>( new Image(pixbuf, x, y) );
}
Image::Image()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Goocanvas::ItemSimple(Glib::ConstructParams(image_class_.init()))
{
  

}


#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy< Cairo::RefPtr<Cairo::Pattern> > Image::property_pattern() 
{
  return Glib::PropertyProxy< Cairo::RefPtr<Cairo::Pattern> >(this, "pattern");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< Cairo::RefPtr<Cairo::Pattern> > Image::property_pattern() const
{
  return Glib::PropertyProxy_ReadOnly< Cairo::RefPtr<Cairo::Pattern> >(this, "pattern");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<bool> Image::property_scale_to_fit() 
{
  return Glib::PropertyProxy<bool>(this, "scale-to-fit");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<bool> Image::property_scale_to_fit() const
{
  return Glib::PropertyProxy_ReadOnly<bool>(this, "scale-to-fit");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_WriteOnly< Glib::RefPtr<Gdk::Pixbuf> > Image::property_pixbuf() 
{
  return Glib::PropertyProxy_WriteOnly< Glib::RefPtr<Gdk::Pixbuf> >(this, "pixbuf");
}
#endif //GLIBMM_PROPERTIES_ENABLED


} // namespace Goocanvas

