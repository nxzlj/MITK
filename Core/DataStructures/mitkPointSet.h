#ifndef MITKPointSet_H_HEADER_INCLUDED
#define MITKPointSet_H_HEADER_INCLUDED

#include "mitkCommon.h"
#include <mitkBaseData.h>
#include <itkPoint.h>
#include <itkPointSet.h>
#include <itkCovariantVector.h>
#include <vector>
#include <itkDefaultDynamicMeshTraits.h>

namespace mitk {

//##ModelId=3F0177E803A1
//##Documentation
//##@brief DataStructure which stores a list of Points 
//## @ingroup Geometry
//##
//## Each Entry (Point) in the the PointSet has a additional value (bool) to store
//## the selected/unselected state of the Entry(Point).
class PointSet : public BaseData
{
public:
  mitkClassMacro(PointSet, BaseData);

  itkNewMacro(Self);

  typedef itk::DefaultDynamicMeshTraits<bool, 3, 3, mitk::ScalarType> MeshTraits;
  typedef itk::PointSet<bool,3,MeshTraits> PointSetType;
  typedef PointSetType::PointType PointType;
  typedef PointSetType::PointsContainer PointsContainer;
  typedef PointSetType::PointDataContainer::Iterator PointDataIterator;
  typedef PointSetType::PointDataContainer PointDataContainer;

  //##ModelId=3F0177E901BF
	void ExecuteOperation(Operation* operation);

  //##ModelId=3F0177E901C1
	//##Documentation
	//## @brief returns the current size of the point-list
	int GetSize();

  //##ModelId=3F0177E901CC
	//##Documentation
	//## @brief returns the point-list with points and selected Information
  const PointSetType::Pointer GetPointList() const;

  //##ModelId=3F0177E901CE
  //##Documentation
	//## @brief Get the point on the given position
	const PointType GetPoint(int position);

  //##Documentation
	//## @brief Get the point on the given position in itkPoint3D
  const mitk::ITKPoint3D GetItkPoint(int position);

  //##ModelId=3F0177E901DC
	//##Documentation
	//## @brief to get the state selected/unselected of the point on the position
	bool GetSelectInfo(int position);

  //##ModelId=3F05B07B0147
  //##Documentation
	//## @brief returns the number of selected points
	const int GetNumberOfSelected();

  //##ModelId=3F0177E901DE
	//##Documentation
	//## @brief searches a point in the List == point +/- distance
	//##
	//## returns -1 if no point is found
	//## or the position in the list of the first match
	int SearchPoint(ITKPoint3D point, float distance);

	//virtual methods, that need to be implemented
  //##ModelId=3F0177E901EE
	virtual void UpdateOutputInformation();
  //##ModelId=3F0177E901FB
	virtual void SetRequestedRegionToLargestPossibleRegion();
  //##ModelId=3F0177E901FD
	virtual bool RequestedRegionIsOutsideOfTheBufferedRegion();
  //##ModelId=3F0177E901FF
	virtual bool VerifyRequestedRegion();
  //##ModelId=3F0177E9020B
	virtual void SetRequestedRegion(itk::DataObject *data);

protected:
  //##ModelId=3F0177E901BD
	PointSet();

  //##ModelId=3F0177E901BE
	virtual ~PointSet();

private:

  //##ModelId=3F0177E90190
	//##Documentation
	//## @brief List of Points
	PointSetType::Pointer m_PointSet;
};

} // namespace mitk



#endif /* MITKPointSet_H_HEADER_INCLUDED */
