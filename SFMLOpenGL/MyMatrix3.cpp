#include "MyMatrix3.h"

/// <summary>
///	Krystian Sarowski
/// 


/// <summary>
/// Default constructor set all 9 values to zero.
/// </summary>
MyMatrix3::MyMatrix3() :

	m_11{ 0.0 },
	m_12{ 0.0 },
	m_13{ 0.0 },
	m_21{ 0.0 },
	m_22{ 0.0 },
	m_23{ 0.0 },
	m_31{ 0.0 },
	m_32{ 0.0 },
	m_33{ 0.0 }
{
}

/// <summary>
/// Constructor taking in nine doubles.
/// </summary>
/// <param name="t_a11">value in row 1 column 1</param>
/// <param name="t_a12">value in row 1 column 2</param>
/// <param name="t_a13">value in row 1 column 3</param>
/// <param name="t_a21">value in row 2 column 1</param>
/// <param name="t_a22">value in row 2 column 2</param>
/// <param name="t_a23">value in row 2 column 3</param>
/// <param name="t_a31">value in row 3 column 1</param>
/// <param name="t_a32">value in row 3 column 2</param>
/// <param name="t_a33">value in row 3 column 3</param>
MyMatrix3::MyMatrix3(double t_a11, double t_a12, double t_a13, double t_a21, double t_a22, double t_a23, double t_a31, double t_a32, double t_a33) :

	m_11{ t_a11 },
	m_12{ t_a12 },
	m_13{ t_a13 },
	m_21{ t_a21 },
	m_22{ t_a22 },
	m_23{ t_a23 },
	m_31{ t_a31 },
	m_32{ t_a32 },
	m_33{ t_a33 }
{
}

/// <summary>
/// Constructor taking in three vectors.
/// </summary>
/// <param name="t_row1">existing vector used to fill row 1 of the matrix</param>
/// <param name="t_row2">existing vector used to fill row 2 of the matrix</param>
/// <param name="t_row3">existing vector used to fill row 3 of the matrix</param>
MyMatrix3::MyMatrix3(MyVector3 t_row1, MyVector3 t_row2, MyVector3 t_row3) :

	m_11{ t_row1.x },
	m_12{ t_row1.y },
	m_13{ t_row1.z },
	m_21{ t_row2.x },
	m_22{ t_row2.y },
	m_23{ t_row2.z },
	m_31{ t_row3.x },
	m_32{ t_row3.y },
	m_33{ t_row3.z }
{
}

/// <summary>
/// Default destructor.
/// Nothing to release because we only have primitive type data.
/// </summary>
MyMatrix3::~MyMatrix3()
{
}

/// <summary>
/// Function used to change 3 by 3 matrix to a string.
/// </summary>
/// <returns>the matrix as a string in 3 rows with 3 columns, each row surrounded by square brackets</returns>
std::string MyMatrix3::toString() const
{
	const std::string output = "[" + std::to_string(m_11) + "," + std::to_string(m_12) + "," + std::to_string(m_13) 
		+ "] \n[" + std::to_string(m_21) + "," + std::to_string(m_22) + "," + std::to_string(m_23)
		+ "] \n[" + std::to_string(m_31) + "," + std::to_string(m_32) + "," + std::to_string(m_33) + "]";
	return output;
}

/// <summary>
///  Equality operator overloaded.
/// </summary>
/// <param name="t_other">2nd matrix</param>
/// <returns>true if the two matrix are exactly the same</returns>
bool MyMatrix3::operator==(const MyMatrix3 t_other) const
{
	const bool answer{ m_11 == t_other.m_11 && m_12 == t_other.m_12 && m_13 == t_other.m_13 &&
		m_21 == t_other.m_21 && m_22 == t_other.m_22 && m_23 == t_other.m_23 &&
		m_31 == t_other.m_31 && m_32 == t_other.m_32 && m_33 == t_other.m_33 };
	return answer;
}

/// <summary>
///  Inequality operator overloaded.
/// </summary>
/// <param name="t_other">2nd matrix</param>
/// <returns>true if the two matrix are not the same</returns>
bool MyMatrix3::operator!=(const MyMatrix3 t_other) const
{
	const bool answer{ m_11 != t_other.m_11 || m_12 != t_other.m_12 || m_13 != t_other.m_13 ||
		m_21 != t_other.m_21 || m_22 != t_other.m_22 || m_23 != t_other.m_23 ||
		m_31 != t_other.m_31 || m_32 != t_other.m_32 || m_33 != t_other.m_33 };
	return answer;
}


/// <summary>
/// Overload for the addition of 3 by 3 matrix.
/// </summary>
/// <param name="t_other">2nd matrix</param>
/// <returns>matrix sum</returns>
MyMatrix3 MyMatrix3::operator+(const MyMatrix3 t_other) const
{
	//Row 1 addition.
	double new11 = m_11 + t_other.m_11;
	double new12 = m_12 + t_other.m_12;
	double new13 = m_13 + t_other.m_13;

	//Row 2 addition.
	double new21 = m_21 + t_other.m_21;
	double new22 = m_22 + t_other.m_22;
	double new23 = m_23 + t_other.m_23;

	//Row 3 addition.
	double new31 = m_31 + t_other.m_31;
	double new32 = m_32 + t_other.m_32;
	double new33 = m_33 + t_other.m_33;

	return MyMatrix3(new11, new12, new13, new21, new22, new23, new31, new32, new33);
}

/// <summary>
/// Overload for the subtraction of 3 by 3 matrix.
/// </summary>
/// <param name="t_other">2nd matrix</param>
/// <returns>matrix difference</returns>
MyMatrix3 MyMatrix3::operator-(const MyMatrix3 t_other) const
{
	//Row 1 subtraction.
	double new11 = m_11 - t_other.m_11;
	double new12 = m_12 - t_other.m_12;
	double new13 = m_13 - t_other.m_13;

	//Row 2 subtraction.
	double new21 = m_21 - t_other.m_21;
	double new22 = m_22 - t_other.m_22;
	double new23 = m_23 - t_other.m_23;

	//Row 3 subtraction.
	double new31 = m_31 - t_other.m_31;
	double new32 = m_32 - t_other.m_32;
	double new33 = m_33 - t_other.m_33;

	return MyMatrix3(new11, new12, new13, new21, new22, new23, new31, new32, new33);
}

/// <summary>
/// Overload for multiplication of two 3 by 3 matrices by each other.
/// </summary>
/// <param name="t_other">2nd matrix </param>
/// <returns>product matrix resulting from multiplication of two matrices</returns>
MyMatrix3 MyMatrix3::operator*(const MyMatrix3 t_other) const
{
	//Row 1 multiplication.
	double new11 = m_11 * t_other.m_11 + m_12 * t_other.m_21 + m_13 * t_other.m_31;
	double new12 = m_11 * t_other.m_12 + m_12 * t_other.m_22 + m_13 * t_other.m_32;
	double new13 = m_11 * t_other.m_13 + m_12 * t_other.m_23 + m_13 * t_other.m_33;

	//Row 2 multiplication.
	double new21 = m_21 * t_other.m_11 + m_22 * t_other.m_21 + m_23 * t_other.m_31;
	double new22 = m_21 * t_other.m_12 + m_22 * t_other.m_22 + m_23 * t_other.m_32;
	double new23 = m_21 * t_other.m_13 + m_22 * t_other.m_23 + m_23 * t_other.m_33;

	//Row 3 multiplication.
	double new31 = m_31 * t_other.m_11 + m_32 * t_other.m_21 + m_33 * t_other.m_31;
	double new32 = m_31 * t_other.m_12 + m_32 * t_other.m_22 + m_33 * t_other.m_32;
	double new33 = m_31 * t_other.m_13 + m_32 * t_other.m_23 + m_33 * t_other.m_33;

	return MyMatrix3(new11, new12, new13, new21, new22, new23, new31, new32, new33);
}

/// <summary>
/// Overload for multiplication of a 3 by 3 matrix by a vector.
/// </summary>
/// <param name="t_other">existing vector</param>
/// <returns>product vector resulting from multiplication of a matrix and a vector</returns>
MyVector3 MyMatrix3::operator*(const MyVector3 t_vector) const
{
	//Creates a matrix with 1 column ie a vector.
	double new11 = m_11 * t_vector.x + m_12 * t_vector.y + m_13 * t_vector.z;
	double new21 = m_21 * t_vector.x + m_22 * t_vector.y + m_23 * t_vector.z;
	double new31 = m_31 * t_vector.x + m_32 * t_vector.y + m_33 * t_vector.z;

	return MyVector3(new11, new21, new31);
}

/// <summary>
/// Overload for multiplication of a 3 by 3 matrix by a double
/// </summary>
/// <param name="t_scale">number of type double</param>
/// <returns>product matrix of multiplication of a matrix by a scalar</returns>
MyMatrix3 MyMatrix3::operator*(const double t_scale) const
{
	//Row 1 multiplication.
	double new11 = m_11 * t_scale;
	double new12 = m_12 * t_scale;
	double new13 = m_13 * t_scale;

	//Row 2 multiplication.
	double new21 = m_21 * t_scale;
	double new22 = m_22 * t_scale;
	double new23 = m_23 * t_scale;

	//Row 3 multiplication.
	double new31 = m_31 * t_scale;
	double new32 = m_32 * t_scale;
	double new33 = m_33 * t_scale;

	return MyMatrix3(new11, new12, new13, new21, new22, new23, new31, new32, new33);
}

/// <summary>
/// Creates a matrix which is the transpose of the existing matrix.
/// </summary>
/// <returns>matrix that is the transpose of the entered matrix</returns>
MyMatrix3 MyMatrix3::transpose() const
{
	//Column 1 changed to row 1.
	double new11 = m_11;
	double new12 = m_21;
	double new13 = m_31;

	//Column 2 changed to row 2.
	double new21 = m_12;
	double new22 = m_22;
	double new23 = m_32;

	//Column 3 changed to row 3.
	double new31 = m_13;
	double new32 = m_23;
	double new33 = m_33;

	return MyMatrix3(new11, new12, new13, new21, new22, new23, new31, new32, new33);
}

/// <summary>
/// Creates a value that is the determinant of the existing matrix.
/// </summary>
/// <returns>value that is the determinant of the entered matrix</returns>
double MyMatrix3::determinant() const
{
	double line1 = m_11 * (m_22 * m_33 - m_32 * m_23);
	double line2 = m_21 * (m_33 * m_12 - m_32 * m_13);
	double line3 = m_31 * (m_23 * m_12 - m_22 * m_13);

	return (line1 - line2 + line3);
}

/// <summary>
/// Creates a matirx that is the inverse of the existing matrix.
/// </summary>
/// <returns>matrix that is the inverse of the entered matrix</returns>
MyMatrix3 MyMatrix3::inverse() const
{
	//Calcualtions carried out in row 1.
	double new11 = m_33 * m_22 - m_32 * m_23;
	double new12 = m_32 * m_13 - m_33 * m_12;
	double new13 = m_23 * m_12 - m_22 * m_13;

	//Calcualtions carried out in row 2.
	double new21 = m_31 * m_23 - m_33 * m_21;
	double new22 = m_33 * m_11 - m_31 * m_13;
	double new23 = m_21 * m_13 - m_23 * m_11;

	//Calcualtions carried out in row 3.
	double new31 = m_32 * m_21 - m_31 * m_22;
	double new32 = m_31 * m_12 - m_32 * m_11;
	double new33 = m_22 * m_11 - m_21 * m_12;
 
	double oneOverDet = 1 / determinant();

	//New matrix created from the calculations in each row.
	MyMatrix3 newMatrix = { new11, new12, new13, new21, new22, new23, new31, new32, new33 };

	//The inverse matrix of the entered matrix.
	return MyMatrix3(newMatrix * oneOverDet);
}

/// <summary>
/// Gets one of the rows of the matrix and returns it as a vector.
/// </summary>
/// <param name="t_row">row that we want to return as a vector</param>
/// <returns>vector made from the selected row of the matrix</returns>
MyVector3 MyMatrix3::row(const int t_row) const
{
	if (t_row == 0)
	{
		return MyVector3(m_11, m_12, m_13);
	}
	else if (t_row == 1)
	{
		return MyVector3(m_21, m_22, m_23);
	}
	else if (t_row == 2)
	{
		return MyVector3(m_31, m_32, m_33);
	}
	else
	{
		return MyVector3();
	}
}

/// <summary>
/// Gets one of the columns of the matrix and returns it as a vector.
/// </summary>
/// <param name="t_row">column that we want to return as a vector</param>
/// <returns>vector made from the selected column of the matrix</returns>
MyVector3 MyMatrix3::column(const int t_column) const
{
	if (t_column == 0)
	{
		return MyVector3(m_11, m_21, m_31);
	}
	else if(t_column == 1)
	{
		return MyVector3(m_12, m_22, m_32);
	}
	else if(t_column == 2)
	{
		return MyVector3(m_13, m_23, m_33);
	}
	else
	{
		return MyVector3();
	}
}

/// <summary>
/// Creates a matrix that when multiplied by another matrix
/// it will rotate that matrix by the given angle around the Z axis.
/// </summary>
/// <param name="t_angleRadians">angle by which we want to rotate the object</param>
/// <returns>matrix that will preform the rotation by the entered angle around the Z axis</returns>
MyMatrix3 MyMatrix3::rotationZ(const double t_angleRadians)
{	
	//Row 1.
	double new11 = cos(t_angleRadians);
	double new12 = -sin(t_angleRadians);
	double new13 = 0;

	//Row 2.
	double new21 = sin(t_angleRadians);
	double new22 = cos(t_angleRadians);
	double new23 = 0;

	//Row 3.
	double new31 = 0;
	double new32 = 0;
	double new33 = 1;

	return MyMatrix3(new11, new12, new13, new21, new22, new23, new31, new32, new33);
}

/// <summary>
/// Creates a matrix that when multiplied by another matrix
/// it will rotate that matrix by the given angle around the Y axis.
/// </summary>
/// <param name="t_angleRadians">angle by which we want to rotate the object</param>
/// <returns>matrix that will preform the rotation by the entered angle around the Y axis</returns>
MyMatrix3 MyMatrix3::rotationY(const double t_angleRadians)
{
	//Row 1.
	double new11 = cos(t_angleRadians);
	double new12 = 0;
	double new13 = sin(t_angleRadians);

	//Row 2.
	double new21 = 0;
	double new22 = 1;
	double new23 = 0;

	//Row 3.
	double new31 = -sin(t_angleRadians);
	double new32 = 0;
	double new33 = cos(t_angleRadians);

	return MyMatrix3(new11, new12, new13, new21, new22, new23, new31, new32, new33);
}

/// <summary>
/// Creates a matrix that when multiplied by another matrix
/// it will rotate that matrix by the given angle around the X axis.
/// </summary>
/// <param name="t_angleRadians">angle by which we want to rotate the object</param>
/// <returns>matrix that will preform the rotation by the entered angle around the X axis</returns>
MyMatrix3 MyMatrix3::rotationX(const double t_angleRadians)
{
	//Row 1.
	double new11 = 1;
	double new12 = 0;
	double new13 = 0;

	//Row 2.
	double new21 = 0;
	double new22 = cos(t_angleRadians);
	double new23 = -sin(t_angleRadians);

	//Row 3.
	double new31 = 0;
	double new32 = sin(t_angleRadians);
	double new33 = cos(t_angleRadians);

	return MyMatrix3(new11, new12, new13, new21, new22, new23, new31, new32, new33);
}

/// <summary>
/// Creates a matrix from the entered vector that when multiplied by another vector
/// it will move that vector in the direction and distance of the vector used to create this matrix.
/// </summary>
/// <param name="t_displacement">vector used to create the translation matrix</param>
/// <returns>matrix that will move a vector by the entered vector</returns>
MyMatrix3 MyMatrix3::translation(const MyVector3 t_displacement)
{
	//Row 1.
	double new11 = 1;
	double new12 = 0;
	double new13 = t_displacement.x;

	//Row 2.
	double new21 = 0;
	double new22 = 1;
	double new23 = t_displacement.y;

	//Row 3.
	double new31 = 0;
	double new32 = 0;
	double new33 = t_displacement.z;

	return MyMatrix3(new11, new12, new13, new21, new22, new23, new31, new32, new33);
}

/// <summary>
/// Creates a matrix from the entered scaling factor that when multiplied by a vector
/// it will enlarge that vector by the entered scaling factor.
/// </summary>
/// <param name="t_scalingfactor">value by which we want to scale another vector</param>
/// <returns>matrix that scale a vector by the scaling factor</returns>
MyMatrix3 MyMatrix3::scale(const double t_scalingfactor)
{
	//Row 1.
	double new11 = t_scalingfactor;
	double new12 = 0;
	double new13 = 0;
	
	//Row 2.
	double new21 = 0;
	double new22 = t_scalingfactor;
	double new23 = 0;

	//Row 3.
	double new31 = 0;
	double new32 = 0;
	double new33 = t_scalingfactor;

	return MyMatrix3(new11, new12, new13, new21, new22, new23, new31, new32, new33);
}
