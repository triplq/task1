#include <iostream>

struct Book
{
private:
    std::string name;
    std::string author;
    unsigned int year;
    unsigned int pages;

public:
    Book(std::string n, std::string a, unsigned int y, unsigned int p)
    {
        if(n.empty() || a.empty() || y > 2025)
            throw std::invalid_argument("Нет такой книги!");

        name = n;
        author = a;
        year = y;
        pages = p;
    }
    Book() { }

    unsigned int getPages() { return pages; }
    std::string getAuthor() { return author; }
};

unsigned int counting(Book* books)
{
    unsigned int all_pages{0};
    for(unsigned i = 0; !books[i].getAuthor().empty(); i++)
        all_pages += books[i].getPages();

    return all_pages;
}

int main()
{
    try
    {
        Book book1{"Harry Potter", "J.K.", 1997, 352};
        Book book2{"The catcher in the rye", "J.D.", 1951, 224};
        Book book3{"Mrs Dalloway", "V.W.", 1925, 224};
        Book book_empty{}; 
        
        // использование книги-заглушки, т.к. в соответствии с ТЗ я не могу передавать размер массива в параметр 
        // и могу использовать только стандартный массив C++. Т.о. нет проверка конца массива осуществляется с 
        // помощью книги-заглушки чтобы избежать UB и выхода за границу

        //Book book_error{"QWE", "", 2022, 211}; проверка исключения 

        Book books[]{book1, book2, book3, book_empty};

        std::cout << counting(books) << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}