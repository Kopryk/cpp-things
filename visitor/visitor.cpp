#include <memory>
#include <vector>
#include <variant>

// Simple example for visitor design pattern
// inspired by https://youtu.be/PEcy1vYHb8A

namespace OOP {
	class Shape
	{
	public:
		int a, b;

		virtual void draw() = 0;
	};

	class Triangle : public Shape
	{
	public:
		void draw() override {}
	};

	class Rectangle : public Shape
	{
	public:
		void draw() override {};
	};


	void foo()
	{
		std::vector<std::unique_ptr<Shape>> shapes{ std::make_unique<Triangle>(),
	std::make_unique<Rectangle>() };

		for (const auto& shape : shapes)
		{
			shape->draw();
		}
	}
}

namespace MODERN_CPP
{

	class Triangle
	{
	public:
		void draw() const {}
	};

	class Rectangle
	{
	public:
		void draw() const {}
	};


	class Draw
	{
	public:
		void operator() (const Triangle& triangle) const
		{
			triangle.draw();
		}

		void operator() (const Rectangle& rectangle) const
		{
			rectangle.draw();
		}

	};


	void foo()
	{

		using Shape = std::variant<Triangle, Rectangle>;

		std::vector<Shape> shapes{ Triangle{}, Rectangle{} };

		for (auto& shape : shapes)
		{
			std::visit(Draw{}, shape);
		}
	}


}
