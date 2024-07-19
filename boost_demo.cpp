#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/regex.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/any.hpp>
#include <boost/optional.hpp>
#include <boost/filesystem.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/variant.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/thread.hpp>
#include <boost/asio.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp> // Added to support matrix printing
#include <boost/algorithm/clamp.hpp>
#include <boost/random.hpp>
#include <boost/functional/hash.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/container/vector.hpp>
#include <boost/chrono.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/breadth_first_search.hpp>
#include <boost/graph/visitors.hpp>

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

// 1. Boost.Algorithm - String manipulation
void demonstrate_boost_algorithm() {
    std::string text = "Boost Libraries are Awesome!";
    boost::to_upper(text);
    std::cout << "Uppercase: " << text << std::endl;
    boost::to_lower(text);
    std::cout << "Lowercase: " << text << std::endl;
    std::vector<std::string> words;
    boost::split(words, text, boost::is_any_of(" "));
    std::cout << "Words: ";
    for (const auto& word : words) {
        std::cout << word << " ";
    }
    std::cout << std::endl;
}

// 2. Boost.LexicalCast - Type casting
void demonstrate_boost_lexical_cast() {
    std::string number = "123";
    int num = boost::lexical_cast<int>(number);
    std::cout << "String to int: " << num << std::endl;

    float pi = 3.14159f;
    std::string pi_str = boost::lexical_cast<std::string>(pi);
    std::cout << "Float to string: " << pi_str << std::endl;
}

// 3. Boost.Regex - Regular expressions
void demonstrate_boost_regex() {
    std::string text = "My email is example@boost.org";
    boost::regex email_regex(R"((\w+)(\.|_)?(\w*)@(\w+)\.(\w+))");
    boost::smatch matches;
    if (boost::regex_search(text, matches, email_regex)) {
        std::cout << "Found email: " << matches[0] << std::endl;
    }
}

// 4. Boost.UUID - UUID generation
void demonstrate_boost_uuid() {
    boost::uuids::uuid uuid = boost::uuids::random_generator()();
    std::cout << "Generated UUID: " << uuid << std::endl;
}

// 5. Boost.Any - Type-safe container for single values of any type
void demonstrate_boost_any() {
    boost::any variable = 42;
    try {
        std::cout << "Any value: " << boost::any_cast<int>(variable) << std::endl;
    } catch (const boost::bad_any_cast &e) {
        std::cout << "Bad any cast: " << e.what() << std::endl;
    }
}

// 6. Boost.Optional - Optional values
void demonstrate_boost_optional() {
    boost::optional<int> optional_value = 10;
    if (optional_value) {
        std::cout << "Optional value: " << optional_value.value() << std::endl;
    }
}

// 7. Boost.Filesystem - File and directory handling
void demonstrate_boost_filesystem() {
    boost::filesystem::path p{"example.txt"};
    std::ofstream ofs(p.string());
    ofs << "Boost Filesystem Example";
    ofs.close();
    std::cout << "File created: " << p << std::endl;
}

// 8. Boost.DateTime - Date and time handling
void demonstrate_boost_datetime() {
    boost::posix_time::ptime now = boost::posix_time::second_clock::local_time();
    std::cout << "Current time: " << now << std::endl;
}

// 9. Boost.Variant - Safe, generic, discriminated union container
void demonstrate_boost_variant() {
    boost::variant<int, std::string> v;
    v = 42;
    std::cout << "Variant holds: " << boost::get<int>(v) << std::endl;
    v = "Hello, Boost!";
    std::cout << "Variant holds: " << boost::get<std::string>(v) << std::endl;
}

// 10. Boost.Shared_Ptr - Smart pointers
void demonstrate_boost_shared_ptr() {
    boost::shared_ptr<int> p = boost::make_shared<int>(10);
    std::cout << "Shared pointer value: " << *p << std::endl;
}

// 11. Boost.Thread - Multithreading
void print_hello() {
    std::cout << "Hello from thread!" << std::endl;
}
void demonstrate_boost_thread() {
    boost::thread t(print_hello);
    t.join();
}

// 12. Boost.ASIO - Asynchronous I/O
void print_message(const boost::system::error_code& /*e*/) {
    std::cout << "Boost ASIO example" << std::endl;
}
void demonstrate_boost_asio() {
    boost::asio::io_context io;
    boost::asio::steady_timer t(io, boost::asio::chrono::seconds(1));
    t.async_wait(&print_message);
    io.run();
}

// 13. Boost.Numeric.Ublas - Linear algebra
void demonstrate_boost_ublas() {
    boost::numeric::ublas::matrix<int> m(3, 3);
    for (unsigned i = 0; i < m.size1(); ++i)
        for (unsigned j = 0; j < m.size2(); ++j)
            m(i, j) = 3 * i + j;
    std::cout << "Matrix:\n" << m << std::endl;
}

// 14. Boost.Algorithm - Clamping
void demonstrate_boost_clamp() {
    int x = 15;
    std::cout << "Clamped value: " << boost::algorithm::clamp(x, 10, 20) << std::endl;
}

// 15. Boost.Random - Random number generation
void demonstrate_boost_random() {
    boost::random::mt19937 gen;
    boost::random::uniform_int_distribution<> dist(1, 100);
    std::cout << "Random number: " << dist(gen) << std::endl;
}

// 16. Boost.Functional.Hash - Hashing
void demonstrate_boost_hash() {
    std::string s = "Boost";
    std::size_t hash_value = boost::hash<std::string>()(s);
    std::cout << "Hash value: " << hash_value << std::endl;
}

// 17. Boost.Range - Range algorithms
void demonstrate_boost_range() {
    std::vector<int> v{1, 2, 3, 4, 5};
    std::cout << "Range: ";
    for (auto x : v) std::cout << x << " ";
    std::cout << std::endl;
}

// 18. Boost.Container - Containers
void demonstrate_boost_container() {
    boost::container::vector<int> v{1, 2, 3, 4, 5};
    std::cout << "Container: ";
    for (auto x : v) std::cout << x << " ";
    std::cout << std::endl;
}

// 19. Boost.Chrono - Chrono
void demonstrate_boost_chrono() {
    boost::chrono::steady_clock::time_point start = boost::chrono::steady_clock::now();
    boost::this_thread::sleep_for(boost::chrono::seconds(1));
    boost::chrono::steady_clock::time_point end = boost::chrono::steady_clock::now();
    boost::chrono::duration<double> sec = end - start;
    std::cout << "Slept for " << sec.count() << " seconds" << std::endl;
}

// Define the BFS visitor outside the function scope to avoid issues with template members
class bfs_visitor : public boost::default_bfs_visitor {
public:
    template <typename Vertex, typename Graph>
    void discover_vertex(Vertex v, const Graph& g) const {
        std::cout << "Visited vertex: " << v << std::endl;
    }
};

// 20. Boost.Graph - Graphs
void demonstrate_boost_graph() {
    typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS> Graph;
    Graph g;

    // Add vertices
    boost::add_vertex(g);
    boost::add_vertex(g);
    boost::add_vertex(g);

    // Add edges
    boost::add_edge(0, 1, g);
    boost::add_edge(1, 2, g);
    boost::add_edge(2, 0, g);

    // Perform BFS
    bfs_visitor vis;
    boost::breadth_first_search(g, boost::vertex(0, g), boost::visitor(vis));
}

int main() {
    std::cout << "Demonstrating Boost Libraries" << std::endl;

    demonstrate_boost_algorithm();
    demonstrate_boost_lexical_cast();
    demonstrate_boost_regex();
    demonstrate_boost_uuid();
    demonstrate_boost_any();
    demonstrate_boost_optional();
    demonstrate_boost_filesystem();
    demonstrate_boost_datetime();
    demonstrate_boost_variant();
    demonstrate_boost_shared_ptr();
    demonstrate_boost_thread();
    demonstrate_boost_asio();
    demonstrate_boost_ublas();
    demonstrate_boost_clamp();
    demonstrate_boost_random();
    demonstrate_boost_hash();
    demonstrate_boost_range();
    demonstrate_boost_container();
    demonstrate_boost_chrono();
    demonstrate_boost_graph();

    return 0;
}
