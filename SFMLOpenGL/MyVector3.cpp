/// <summary>
/// Vector 3 class
///	Krystian Sarowski
/// </summary>
#include "MyVector3.h"
#include <string.h>
#define PI           3.14159265358979323846



#pragma region constructors


/// <summary>
/// Defautl constructor set all 3 values to zero
/// </summary>
MyVector3::MyVector3() :
	x{ 0.0 },
	y{ 0.0 },
	z{ 0.0 }
{
}

/// <summary>
/// Constructor taking three doubles
/// </summary>
/// <param name="t_x">X component</param>
/// <param name="t_y">Y component</param>
/// <param name="t_z">Z component</param>
MyVector3::MyVector3(double t_x, double t_y, double t_z) :
	x{ t_x },
	y{ t_y },
	z{ t_z }
{
}

/// <summary>
/// Constructor taking a SFML vector3f
/// Cast it as a float
/// </summary>
/// <param name="t_sfVector">existing vector</param>
MyVector3::MyVector3(sf::Vector3f t_sfVector)
{
	x = static_cast<float>(t_sfVector.x);
	y = static_cast<float>(t_sfVector.y);
	z = static_cast<float>(t_sfVector.z);
}

/// <summary>
/// Constructor taking a SFML vector3i
/// Cast it as a int
/// </summary>
/// <param name="t_sfVector">existing vector</param>
MyVector3::MyVector3(sf::Vector3i t_sfVector)
{
	x = static_cast<int>(t_sfVector.x);
	y = static_cast<int>(t_sfVector.y);
	z = static_cast<int>(t_sfVector.z);
}

/// <summary>
/// Constructor taking a SFML vector2i
/// Cast it as an int with 0 as z component
/// </summary>
/// <param name="t_sfVector">existing vector</param>
MyVector3::MyVector3(sf::Vector2i t_sfVector)
{
	x = static_cast<int>(t_sfVector.x);
	y = static_cast<int>(t_sfVector.y);
	z = static_cast<int>(0);			//Sets junk value to 0 for z plane.
}

/// <summary>
/// Constructor taking a SFML vector2u
/// Cast it as an unsigned int with 0 as z component
/// </summary>
/// <param name="t_sfVector">existing vector</param>
MyVector3::MyVector3(sf::Vector2u t_sfVector)
{
	x = static_cast<unsigned int>(t_sfVector.x);
	y = static_cast<unsigned int>(t_sfVector.y);
	z = static_cast<unsigned int>(0);	//Sets junk value to 0 for z plane.
}

MyVector3::operator sf::Vector2u()
{
	double newX{ x };
	double newY{ y };
	if (newX < 0)
	{
		newX = -(newX);		//Changes it current x to a poitive one if its currently negative.
	}

	if (newY < 0)
	{
		newY = -(newY);		//Changes it current y to a poitive one if its currently negative.
	}

	return sf::Vector2u(static_cast<unsigned int>(newY), static_cast<unsigned int>(newY));
}

/// <summary>
/// Constructor taking a SFML vector2f
/// Cast it as an float with 0 as z component
/// </summary>
/// <param name="t_sfVector">existing vector</param>
MyVector3::MyVector3(sf::Vector2f t_sfVector)
{
	x = static_cast<float>(t_sfVector.x);
	y = static_cast<float>(t_sfVector.y);
	z = static_cast<float>(0);			//Sets junk value to 0 for z plane.
}

#pragma endregion

/// <summary>
/// default destructor
/// nothing to release because we only have
/// primitive type data
/// </summary>
MyVector3::~MyVector3()
{
}

#pragma region methods
/// <summary>
/// 
/// </summary>
/// <returns>the vector as a string surrounded by square brackets and seperated by commas</returns>
std::string MyVector3::toString()
{
	const std::string output = "[" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z) + "]";
	return output;
}

/// <summary>
/// Gets the length/magnitude of the vector
/// </summary>
/// <returns>lenght/magnitude</returns>
double MyVector3::length() const
{
	return sqrt(x * x + y * y + z * z);
}

/// <summary>
/// Calculates the length squared of the vector
/// </summary>
/// <returns>length squared</returns>
double MyVector3::lengthSquared() const
{
	return (x * x + y * y + z * z);
}

/// <summary>
/// dot product of the two vectors
/// </summary>
/// <param name="other">the second vector</param>
/// <returns>dot product</returns>
double MyVector3::dot(const MyVector3 t_other) const
{
	return (x * t_other.x) + (y * t_other.y) + (z * t_other.z);
}


/// <summary>
/// cross product of the two vectors
/// </summary>
/// <param name="other">the second vector</param>
/// <returns>cross product</returns>
MyVector3 MyVector3::crossProduct(const MyVector3 t_other) const
{
	//Result = y1 * z2 - z1 * y2
	double newX = y * t_other.z - z * t_other.y;

	//Result = z1 * x2 - x1 * z2
	double newY = z * t_other.x - x * t_other.z;

	//Result = x1 * y2 - y1 * x2
	double newZ = x * t_other.y - y * t_other.x;


	return MyVector3(newX, newY, newZ);
}

/// <summary>
/// Get a vector of lenght 1 of the current vector
/// Null vector returns null vector
/// </summary>
/// <returns>new vector of length 1</returns>
MyVector3 MyVector3::unit() const
{

	double magnitude = length();

	//Checks if this is not a null vector.
	if ((x != 0) || (y != 0) || (z != 0))
	{
		//Returns new unit vector which results from dividing both x, y and z by the magnitude (or length).
		return MyVector3(x / magnitude, y / magnitude, z / magnitude);
	}

	else
	{
		//Returns the null vector.
		return MyVector3(x, y, z);
	}
}

/// <summary>
/// Changes the lenght of the current vector to 1
/// Null vector returns null vector
/// </summary>
void MyVector3::normalise()
{
	//Checks if this is not a null vector.
	if ((x != 0) || (y != 0) || (z != 0))
	{
		//Calculates the magnitude before the x and y are changed.
		double magnitude = length();

		//Changes the x and y of the entered vector by dividing them both by the magnitude.
		x = x / magnitude;
		y = y / magnitude;
		z = z / magnitude;
	}

	else
	{
		//The values stay as null values.
		x = x;
		y = y;
		z = z;
	}

	return;
}


/// <summary>
/// Returns the angle between the two vectors
/// </summary>
/// <param name="t_other">second vector</param>
/// <returns>angle in degrees</returns>
double MyVector3::angleBetween(MyVector3 t_other) const
{
	//Formula cosAng = vect1 dot vect2 / mag(vect1) * mag(vect2).

	//Top line of the formula for angle between ie dot product.
	double topLine = dot(t_other);

	//Bottom line of the formula for angle between ie magnitude of vect1 * magnitude of vect2.
	double bottomLine = length() * t_other.length();

	//Cos inverse of the dot product divided by the magnitude of vect1 * magnitude of vect2 
	//which is converted to degrees using 180 divided by PI.
	double angle = acos(topLine / bottomLine) * 180 / PI;

	return angle;
}

/// <summary>
/// Projects a vector onto this vector
/// the returned vector is parallel to this vector
/// </summary>
/// <param name="t_other">the vector we want to project</param>
/// <returns>parallel vector that we projected</returns>
MyVector3 MyVector3::projection(const MyVector3 t_other) const
{
	//Formula vect1 projection (vect2) = (vect1.vect2) / mag(vect1) * vect1 / mag(vect1).

	//Dot product of vect1 and vect2 divided by magnitude squared of vect1.
	double scale = dot(t_other) / lengthSquared();

	double newX = x * scale;
	double newY = y * scale;
	double newZ = z * scale;

	return MyVector3(newX, newY, newZ);
}

/// <summary>
/// rejection the remainder after projection 
/// or the perpendicular component of the vector being projected
/// </summary>
/// <param name="t_other">vector were projecting/rejecting</param>
/// <returns>perpendicular vector that we rejected</returns>
MyVector3 MyVector3::rejection(const MyVector3 t_other) const
{
	//Formula vect1 rejection (vect2) = vect2 - (vect1 projection (vect2)).

	//Returns x, y and z that the result of vect2 - (vect1 projection (vect2)).
	return MyVector3(MyVector3(t_other) - projection(t_other));
}


#pragma endregion

#pragma region operators

/// <summary>
///  equality operator overloaded
/// </summary>
/// <param name="t_right">2nd vector</param>
/// <returns>true if same vectors</returns>
bool MyVector3::operator==(const MyVector3 t_right) const
{
	//Result of check for equality either true or false
	const bool answer{ x == t_right.x && y == t_right.y && z == t_right.z };
	return answer;
}

/// <summary>
/// overloaded inequality 
/// </summary>
/// <param name="t_right">2nd vector</param>
/// <returns>true if not the same vectors</returns>

bool MyVector3::operator!=(const MyVector3 t_right) const
{
	//Result of check for inequality either true or false
	const bool answer{ x != t_right.x || y != t_right.y || z != t_right.z };
	return answer;
}

/// <summary>
/// overload for the addition of 3D vectors
/// </summary>
/// <param name="t_right">2nd vector</param>
/// <returns>vector sum</returns>
MyVector3 MyVector3::operator+(const MyVector3 t_right) const
{
	//Vector = x1 + x2 , y1 + y2 , z1 + z2
	return MyVector3(x + t_right.x, y + t_right.y, z + t_right.z);
}

/// <summary>
/// overload for subtraction of 3D vectors
/// </summary>
/// <param name="t_right">2nd vector</param>
/// <returns>vector difference</returns>
MyVector3 MyVector3::operator-(const MyVector3 t_right) const
{
	//Vector = x1 - x2 , y1 - y2 , z1 - z2
	return MyVector3(x - t_right.x, y - t_right.y, z - t_right.z);
}

/// <summary>
/// overload for multiplication by a double
/// </summary>
/// <param name="scalar"></param>
/// <returns>product of the vector multiplied by the scalar</returns>
MyVector3 MyVector3::operator*(const double t_scalar) const
{
	return MyVector3(x * t_scalar, y * t_scalar, z * t_scalar);
}

/// <summary>
/// overload of multiplication by a float
/// </summary>
/// <param name="scalar"></param>
/// <returns>product of the vector multiplied by the scalar</returns>
MyVector3 MyVector3::operator*(const float t_scalar) const
{
	return MyVector3(x * t_scalar, y * t_scalar, z * t_scalar);
}

/// <summary>
/// overload of multiplication by an int
/// </summary>
/// <param name="scalar"></param>
/// <returns>product of the vector multiplied by the scalar</returns>
MyVector3 MyVector3::operator*(const int t_scalar) const
{
	return MyVector3(x * t_scalar, y * t_scalar, z * t_scalar);
}

/// <summary>
/// overload of divide operator by a double 
/// </summary>
/// <param name="t_divisor">divide by</param>
/// <returns>quotient of the vector divided by the divisor</returns>
MyVector3 MyVector3::operator/(const double t_divisor) const
{
	if (t_divisor != 0)		//Divison by 0 not allowed.
	{
		return MyVector3(x / t_divisor, y / t_divisor, z / t_divisor);
	}

	return MyVector3();
}

/// <summary>
/// overload of divide operator by a float
/// </summary>
/// <param name="t_divisor">divide by</param>
/// <returns>quotient of the vector divided by the divisor</returns>
MyVector3 MyVector3::operator/(const float t_divisor) const
{
	if (t_divisor != 0)		//Divison by 0 not allowed.
	{
		return MyVector3(x / t_divisor, y / t_divisor, z / t_divisor);
	}

	return MyVector3();
}

/// <summary>
/// overload of divide operator by a int
/// </summary>
/// <param name="t_divisor">divide by</param>
/// <returns>quotient of the vector divided by the divisor</returns>
MyVector3 MyVector3::operator/(const int t_divisor) const
{
	if (t_divisor != 0)		//Divison by 0 not allowed.
	{
		return MyVector3(x / t_divisor, y / t_divisor, z / t_divisor);
	}

	return MyVector3();
}


/// <summary>
/// overload for plusequals operator
/// this not a const operation becuase the vector changes
/// </summary>
/// <param name="t_right">vector to add</param>
/// <returns>Changes the first vector to the sum of itself plus second vector</returns>
MyVector3 MyVector3::operator+=(const MyVector3 t_right)
{
	return MyVector3(x += t_right.x, y += t_right.y, z += t_right.z);
}

/// <summary>
/// overload for the minusequals operator
/// this not a const operation becuase the vector changes
/// </summary>
/// <param name="t_right">vector to subtract</param>
/// <returns>Changes the first vector to the difference of itself minus second vector</returns>
MyVector3 MyVector3::operator-=(const MyVector3 t_right)
{
	return MyVector3(x -= t_right.x, y -= t_right.y, z -= t_right.z);
}



/// <summary>
/// overload of the negavive operator
/// </summary>
/// <returns>negative/opposite sign to the one entered</returns>
MyVector3 MyVector3::operator-()
{
	return MyVector3(-x, -y, -z);
}
#pragma endregion


