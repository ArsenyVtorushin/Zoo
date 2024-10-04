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
		price(456),
		countOfLegs(4),
		width(1),
		height(1),
		depth(1),
		material("wood"), 
		color("pink"),
		article("re766"),
		name("Vladick")
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
		this->price = price;
		this->countOfLegs = countOfLegs;

		this->height = height;
		this->width = width;
		this->depth = depth;

		this->material = material;
		this->color = color;
		this->article = article;
		this->name = name;
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
		return this->width * this->height * this->depth;
	}

	int GetPrice()const
	{
		return this->price;
	}
	void SetPrice(int newPrice)
	{
		this->price = newPrice;
	}

	int GetCountOfLegs()const
	{
		return this->countOfLegs;
	}
	void SetCountOfLegs(int newCountOfLegs)
	{
		this->countOfLegs = newCountOfLegs;
	}


	float GetWidth()const
	{
		return this->width;
	}
	void SetWidth(float newWidth)
	{
		this->width = newWidth;
	}

	float GetHeight()const
	{
		return this->height;
	}
	void SetHeight(float newHeight)
	{
		this->height = newHeight;
	}

	float GetDepth()const
	{
		return this->depth;
	}
	void SetDepth(float newDepth)
	{
		this->depth = newDepth;
	}


	std::string GetMaterial()const
	{
		return this->material;
	}
	void SetMaterial(std::string newMaterial)
	{
		this->material = newMaterial;
	}

	std::string GetColor()const
	{
		return this->color;
	}
	void SetColor(std::string newColor)
	{
		this->color = newColor;
	}

	std::string GetArticle()const
	{
		return this->article;
	}
	void SetArticle(std::string newArticle)
	{
		this->article = newArticle;
	}

	std::string GetName()const
	{
		return this->name;
	}
	void SetName(std::string newName)
	{
		this->name = newName;
	}


private:

	int price;
	int countOfLegs;

	float height;
	float width;
	float depth;

	std::string material;
	std::string color;
	std::string article;
	std::string name;

};


class Cat
{
public:
	Cat() :name("Nurebeckc"), age(1), sex(false) {}

	Cat(std::string name, int age, bool sex)
		:name(name),
		age(age),
		sex(sex)
	{}

	std::string GetName() const
	{
		return this->name;
	}
	void SetName(std::string name) 
	{ 
		this->name = name;
	}

	int GetAge() const
	{
		return this->age;
	}
	void SetAge(int age) 
	{ 
		this->age = age;
	}

	bool GetSex() const
	{
		return this->sex;
	}
	void SetSex(bool sex) 
	{ 
		this->sex = sex;
	}

	std::string Info()const 
	{
		std::string info;
		info = "Name: " + this->name + ", ";
		info += "Age: " + std::to_string(this->age) + ", ";
		info += "Sex: " + (this->sex) ? "male" : "female";
		return info;
	}
	// Связанные классы
	// Использование
	// Приминение
	   // Агрегация
	// Композиция
	//

private:
	std::string name;
	int age;
	bool sex;

};
//надо добавить способы хранить добавлять и удалять котов в гостинице
// так же не забыть про то что на котов надо смотреть

class ZooHotel 
{
public:

	ZooHotel() 
	{
		this->name = "Default hotel";
		this->cats = nullptr;
		this->countOfCats = 0;
	}

    // Конструктор копирования обязательно прописывается для классов, в которых управляет данными
	
	ZooHotel(const ZooHotel& other)
	{
		this->name = other.name;
		this->countOfCats = other.countOfCats;
		this->cats = new Cat[countOfCats];

		for (int i = 0; i < this->countOfCats; i++)
		{
			this->cats[i] = other[i];
		}
	}

	//Конструктор переноса 

	ZooHotel(ZooHotel&& other)
	{
		this->name = "Default hotel";
		this->cats = nullptr;
		this->countOfCats = 0;
		std::swap(this->name, other.name);
		std::swap(this->cats, other.cats);
		std::swap(this->countOfCats, other.countOfCats);
	}

	~ZooHotel()
	{
		if (this->cats)
		{
			delete[] this->cats;
		}
	}

	void AddCat(Cat& newCat) 
	{
		if (!this->cats)
		{
			this->countOfCats += 1;
			this->cats = new Cat[countOfCats]{};
			this->cats[countOfCats - 1] = newCat;
		}
		else 
		{
			auto tmp = new Cat[countOfCats + 1]{};

			for (int i = 0; i < countOfCats; i++)
			{
				tmp[i] = cats[i];
			}

			tmp[countOfCats] = newCat;
			this->countOfCats += 1;
			std::swap(tmp, this->cats);
			delete[] tmp;
		}
	}

	void KickOut(int i) 
	{
		if (this->countOfCats == 1)
		{
			delete[] this->cats;
			this->cats = nullptr;
			this->countOfCats = 0;
			return;
		}
		if (countOfCats)
		{
			auto tmp = new Cat[countOfCats - 1]{};

			for (int j = 0; j < i; j++)
			{
				tmp[j] = cats[j];
			}

			for (int j = i + 1; j < countOfCats; j++)
			{
				tmp[j - 1] = cats[j];
			}

			std::swap(tmp, this->cats);
			delete[]tmp;
			this->countOfCats -= 1;
		}
	}

	int size()const 
	{
		return this->countOfCats;
	}

	Cat& operator[](int i) 
	{
		return  this->cats[i];
	}

	const Cat& operator[](int i)const 
	{
		return  this->cats[i];
	}

private:

	std::string name;
	Cat* cats;
	int countOfCats;
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