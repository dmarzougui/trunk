/*************************************************************************
*  Copyright (C) 2004 by Janek Kozicki                                   *
*  cosurgi@berlios.de                                                    *
*                                                                        *
*  This program is free software; it is licensed under the terms of the  *
*  GNU General Public License v2 or later. See file LICENSE for details. *
*************************************************************************/

#pragma once

#include<yade/pkg-common/PhysicalParametersEngineUnit.hpp>
#include<yade/core/Body.hpp>
#include<yade/core/MetaBody.hpp>

class FEMSetTextLoader : public PhysicalParametersEngineUnit
{
	private :
		int	 nodeGroupMask
			,tetrahedronGroupMask;

	public :
		string fileName; 

	public :
		virtual void go(	  const shared_ptr<PhysicalParameters>&
					, Body*);
	
		void createNode(	  shared_ptr<Body>& body
					, Vector3r position
					, int id);
					
		void createTetrahedron(   const MetaBody* rootBody
					, shared_ptr<Body>& body
					, int id
					, int id1
					, int id2
					, int id3
					, int id4);

	REGISTER_ATTRIBUTES(PhysicalParametersEngineUnit,(fileName))
	REGISTER_CLASS_NAME(FEMSetTextLoader);
	REGISTER_BASE_CLASS_NAME(PhysicalParametersEngineUnit);

};

REGISTER_SERIALIZABLE(FEMSetTextLoader);

