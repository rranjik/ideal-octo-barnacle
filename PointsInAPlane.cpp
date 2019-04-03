// Problem 2 - Points in a Plane ( Knowledge Base: Linear Algebra )

// This function takes in 4 3D points represented as Vector3 and returns
// "true" - if they lie in the same plane
// "false" - if they do not lie in the same plane
// No two points are the same

bool PointsInAPlane( Vector3 point1, Vector3 point2, Vector3 point3, Vector3 point4 )
{
	if (Vector3Dot(Vector3((point4.x - point1.x),
		(point4.y - point1.y),
		(point4.z - point1.z)), (Vector3Cross(Vector3((point2.x - point1.x),
		(point2.y - point1.y),
			(point2.z - point1.z)), Vector3((point3.x - point1.x),
			(point3.y - point1.y),
				(point3.z - point1.z))))) == 0) {
		return true;
	}
	else return false;
}
