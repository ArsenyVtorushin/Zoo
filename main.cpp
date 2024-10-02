#include <iostream> 
#include <string> 
#include <vector> 

//class Integer 
//{ 
//public: 
// 
// //cпособы создания объектоB 
// Integer():Integer(false, 0u) {} 
// Integer(bool sign, unsigned units):sign(sign), units(units) {} 
// Integer(int number) {} 
// 
// //способы обработки объектов 
// 
// //способы проверки состояний объекта 
// 
// //перегрузки операторы 
// 
//private: 
// 
// //поля данных и методы не для пользователя 
// 
// bool sign; 
// unsigned units; 
//}; 

class Table
{
public:

	Table() :
		price_(456),
		countOfLegs_(4),
		width_(1),
		height_(1),
		depth_(1),
		material_("wood"),
		color_("pink"),
		article_("re766"),
		name_("Vladick")
	{}

	Table
	(
		int price,
		int countOfLegs,

		float height,
		float width,
		float depth,

		std::string material,
		std::string color,
		std::string article,
		std::string name
	)
	{
		price_ = price;
		countOfLegs_ = countOfLegs;

		height_ = height;
		width_ = width;
		depth_ = depth;

		material_ = material;
		color_ = color;
		article_ = article;
		name_ = name;
	}


	void Print()const
	{
		std::cout << "Price: " << GetPrice() << "\n";
		std::cout << "Count of legs: " << GetCountOfLegs() << "\n";

		std::cout << "Width: " << GetWidth() << "\n";
		std::cout << "Height: " << GetHeight() << "\n";
		std::cout << "Depth: " << GetDepth() << "\n";

		std::cout << "Material: " << GetMaterial() << "\n";
		std::cout << "Color: " << GetColor() << "\n";
		std::cout << "Article: " << GetArticle() << "\n";
		std::cout << "GetName: " << GetName() << "\n";
	}

	float GetVolume()const
	{
		return width_ * height_ * depth_;
	}

	int GetPrice()const
	{
		return price_;
	}
	void SetPrice(int newPrice)
	{
		price_ = newPrice;
	}

	int GetCountOfLegs()const
	{
		return countOfLegs_;
	}
	void SetCountOfLegs(int newCountOfLegs)
	{
		countOfLegs_ = newCountOfLegs;
	}


	float GetWidth()const
	{
		return width_;
	}
	void SetWidth(float newWidth)
	{
		width_ = newWidth;
	}

	float GetHeight()const
	{
		return height_;
	}
	void SetHeight(float newHeight)
	{
		height_ = newHeight;
	}

	float GetDepth()const
	{
		return depth_;
	}
	void SetDepth(float newDepth)
	{
		depth_ = newDepth;
	}


	std::string GetMaterial()const
	{
		return material_;
	}
	void SetMaterial(std::string newMaterial)
	{
		material_ = newMaterial;
	}

	std::string GetColor()const
	{
		return color_;
	}
	void SetColor(std::string newColor)
	{
		color_ = newColor;
	}

	std::string GetArticle()const
	{
		return article_;
	}
	void SetArticle(std::string newArticle)
	{
		article_ = newArticle;
	}

	std::string GetName()const
	{
		return name_;
	}
	void SetName(std::string newName)
	{
		name_ = newName;
	}


private:

	int price_;
	int countOfLegs_;

	float height_;
	float width_;
	float depth_;

	std::string material_;
	std::string color_;
	std::string article_;
	std::string name_;

};


class Cat
{
public:
	Cat() :name_("Nurebeckc"), age_(1), sex_(false) {}

	Cat(std::string name, int age, bool sex)
		:name_(name),
		age_(age),
		sex_(sex)
	{}

	std::string GetName() const
	{
		return name_;
	}
	void SetName(std::string name) 
	{ 
		name_ = name; 
	}

	int GetAge() const
	{
		return age_;
	}
	void SetAge(int age) 
	{ 
		age_ = age; 
	}

	bool GetSex() const
	{
		return sex_;
	}
	void SetSex(bool sex) 
	{ 
		sex_ = sex; 
	}

	std::string Info()const 
	{
		std::string info;
		info = "Name: " + name_ + ", ";
		info += "Age: " + std::to_string(age_) + ", ";
		info += "Sex: " + (sex_) ? "male" : "female";
		return info;
	}
	// Связанные классы
	// Использование
	// Приминение
	   // Агрегация
	// Композиция
	//

private:
	std::string name_;
	int age_;
	bool sex_;

};
//надо добавить способы хранить добавлять и удалять котов в гостинице
// так же не забыть про то что на котов надо смотреть

class ZooHotel 
{
public:

	ZooHotel() 
	{
		name_ = "Default hotel";
		cats_ = nullptr;
		countOfCats_ = 0;
	}

    // Конструктор копирования обязательно прописывается для классов, в которых управляет данными
	//
	ZooHotel(const ZooHotel& other)
	{
		name_ = other.name_;
		countOfCats_ = other.countOfCats_;
		cats_ = new Cat[countOfCats_];

		for (int i = 0; i < countOfCats_; i++)
		{
			cats_[i] = other[i];
		}
	}

	//Конструктор переноса 

	ZooHotel(ZooHotel&& other)
	{
		name_ = "Default hotel";
		cats_ = nullptr;
		countOfCats_ = 0;
		std::swap(name_, other.name_);
		std::swap(cats_, other.cats_);
		std::swap(countOfCats_, other.countOfCats_);
	}

	~ZooHotel()
	{
		if (cats_)
		{
			delete[] cats_;
		}
	}

	void AddCat(Cat& newCat) 
	{
		if (!cats_)
		{
			countOfCats_ += 1;
			cats_ = new Cat[countOfCats_]{};
			cats_[countOfCats_ - 1] = newCat;
		}
		else {
			auto tmp = new Cat[countOfCats_ + 1]{};
			for (int i = 0; i < countOfCats_; i++)
			{
				tmp[i] = cats_[i];
			}
			tmp[countOfCats_] = newCat;
			countOfCats_ += 1;
			std::swap(tmp, cats_);
			delete[] tmp;
		}
	}

	void KickOut(int i) 
	{
		if (countOfCats_ == 1)
		{
			delete[]cats_;
			cats_ = nullptr;
			countOfCats_ = 0;
			return;
		}
		if (countOfCats_)
		{
			auto tmp = new Cat[countOfCats_ - 1]{};
			for (int j = 0; j < i; j++)
			{
				tmp[j] = cats_[j];
			}
			for (int j = i + 1; j < countOfCats_; j++)
			{
				tmp[j - 1] = cats_[j];
			}
			std::swap(tmp, cats_);
			delete[]tmp;
			countOfCats_ -= 1;
		}
	}

	int size()const 
	{
		return countOfCats_;
	}

	Cat& operator[](int i) 
	{
		return  cats_[i];
	}

	const Cat& operator[](int i)const 
	{
		return  cats_[i];
	}

private:
	std::string name_;
	Cat* cats_;
	int countOfCats_;
};


void BlackMagic(ZooHotel hotel_other)
{

}

int main()
{
	/*Table myTable;

	std::vector<Table> tableCollection(3);

	tableCollection.push_back(myTable);
	tableCollection[0].SetArticle("uy667");
	tableCollection[0].SetName("Yaropolk");
	tableCollection[0].Print();

	myTable.SetArticle("Nurbeck");
	myTable.SetColor("Black");
	myTable.SetMaterial("Metall");
	myTable.SetCountOfLegs(19);

	tableCollection.push_back(myTable);

	std::cout << "\n\n";

	for (auto& el : tableCollection)
	{
		el.Print();
		std::cout << "\n";
	}*/

	ZooHotel hotel;
	Cat hobo;

	hobo.SetName("Tom");
	hobo.SetAge(5);
	hobo.SetSex(false);
	
	hotel.AddCat(hobo);

	hobo.SetName("Nurbecka");
	hobo.SetAge(2);
	hobo.SetSex(true);

	hotel.AddCat(hobo);

	std::cout << hotel[0].Info();
	std::cout << hotel[1].Info();
	BlackMagic(hotel);

	return 0;
}