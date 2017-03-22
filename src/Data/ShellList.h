#ifndef IQMOL_DATA_SHELLLIST_H
#define IQMOL_DATA_SHELLLIST_H
/*******************************************************************************
       
  Copyright (C) 2011-2015 Andrew Gilbert
           
  This file is part of IQmol, a free molecular visualization program. See
  <http://iqmol.org> for more details.
       
  IQmol is free software: you can redistribute it and/or modify it under the
  terms of the GNU General Public License as published by the Free Software
  Foundation, either version 3 of the License, or (at your option) any later
  version.

  IQmol is distributed in the hope that it will be useful, but WITHOUT ANY
  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
  FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
  details.
      
  You should have received a copy of the GNU General Public License along
  with IQmol.  If not, see <http://www.gnu.org/licenses/>.  
   
********************************************************************************/

#include "QGLViewer/vec.h"
#include "DataList.h"
#include "Shell.h"


namespace IQmol {
namespace Data {

   class ShellList : public List<Shell> {

      friend class boost::serialization::access;

      public:

         Type::ID typeID() const { return Type::ShellList; }

		 /// Returns the (-1,-1,-1) and (1,1,1) octant corners of a rectangular
		 /// box that encloses the significant region of the Shells where 
		 /// significance is determined by thresh.  
         void boundingBox(qglviewer::Vec& min, qglviewer::Vec& max);

         unsigned nBasis() const;

         void serialize(InputArchive& ar, unsigned int const version = 0) {
            serializeList(ar, version);
         }  
         
         void serialize(OutputArchive& ar, unsigned int const version = 0) {
            serializeList(ar, version);
         }  

         void dump() const;
   };

} } // end namespace IQmol::Data

#endif
