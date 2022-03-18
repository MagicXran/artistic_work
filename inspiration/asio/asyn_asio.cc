//
// Created by Administrator on 16/03/2022.
//

#include <iostream>
#include <boost/asio.hpp>
#include <boost/beast/websocket.hpp>
#define BOOST_ASIO_ENABLE_HANDLER_TRACKING

#define MAX_DATA_SIZE 150
#define MIN_DATA_SIZE 3
#define SLEEP_TIME  2

using namespace boost::asio::ip;

class asynServer {
private:
    tcp::acceptor acceptor_;
    tcp::socket sock_;
    tcp::endpoint ep_;
    char data_[MAX_DATA_SIZE + 1] {};

public:
    asynServer(boost::asio::io_context &io_context , const tcp::endpoint &endpoint , tcp::socket sock) : acceptor_(
            io_context , endpoint) , sock_(std::move(sock)) , ep_(endpoint) {
        do_acceptor();
    }

    void do_read() {
        boost::asio::async_read(sock_ , boost::asio::buffer(data_ , MAX_DATA_SIZE) ,
                                [this](const boost::system::error_code &error , std::size_t bytes_transferred) {
                                    if (!error) {
                                        std::cout << data_ << std::endl;
                                    }
                                    do_acceptor();
                                });
    }

    void do_write() {
        std::string respond = "HTTP/1.1 200 OK"
                              "Date: Sun, 18 Oct 2022"
                              "Server: Apache/2.2.14"
                              "Connection: close"
                              "Connect-Type: text/html"
                              "Connect-Length: 26789"
                              "<html>\n"
                              "<head>\n"
                              "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=US-ASCII\">\n"
                              "<title>Class message_queue</title>\n"
                              "<link rel=\"stylesheet\" href=\"../../../../doc/src/boostbook.css\" type=\"text/css\">\n"
                              "<meta name=\"generator\" content=\"DocBook XSL Stylesheets V1.76.1\">\n"
                              "<link rel=\"home\" href=\"../../index.html\" title=\"The Boost C++ Libraries BoostBook Documentation Subset\">\n"
                              "<link rel=\"up\" href=\"../../boost_interprocess_reference.html#header.boost.interprocess.ipc.message_queue_hpp\" title=\"Header &lt;boost/interprocess/ipc/message_queue.hpp&gt;\">\n"
                              "<link rel=\"prev\" href=\"unordered_map_index.html\" title=\"Class template unordered_map_index\">\n"
                              "<link rel=\"next\" href=\"basic_managed_external__id909193.html\" title=\"Class template basic_managed_external_buffer\">\n"
                              "</head>\n"
                              "<body bgcolor=\"white\" text=\"black\" link=\"#0000FF\" vlink=\"#840084\" alink=\"#0000FF\">\n"
                              "<table cellpadding=\"2\" width=\"100%\"><tr>\n"
                              "<td valign=\"top\"><img alt=\"Boost C++ Libraries\" width=\"277\" height=\"86\" src=\"../../../../boost.png\"></td>\n"
                              "<td align=\"center\"><a href=\"../../../../index.html\">Home</a></td>\n"
                              "<td align=\"center\"><a href=\"../../../../libs/libraries.htm\">Libraries</a></td>\n"
                              "<td align=\"center\"><a href=\"http://www.boost.org/users/people.html\">People</a></td>\n"
                              "<td align=\"center\"><a href=\"http://www.boost.org/users/faq.html\">FAQ</a></td>\n"
                              "<td align=\"center\"><a href=\"../../../../more/index.htm\">More</a></td>\n"
                              "</tr></table>\n"
                              "<hr>\n"
                              "<div class=\"spirit-nav\">\n"
                              "<a accesskey=\"p\" href=\"unordered_map_index.html\"><img src=\"../../../../doc/src/images/prev.png\" alt=\"Prev\"></a><a accesskey=\"u\" href=\"../../boost_interprocess_reference.html#header.boost.interprocess.ipc.message_queue_hpp\"><img src=\"../../../../doc/src/images/up.png\" alt=\"Up\"></a><a accesskey=\"h\" href=\"../../index.html\"><img src=\"../../../../doc/src/images/home.png\" alt=\"Home\"></a><a accesskey=\"n\" href=\"basic_managed_external__id909193.html\"><img src=\"../../../../doc/src/images/next.png\" alt=\"Next\"></a>\n"
                              "</div>\n"
                              "<div class=\"refentry\">\n"
                              "<a name=\"boost.interprocess.message_queue\"></a><div class=\"titlepage\"></div>\n"
                              "<div class=\"refnamediv\">\n"
                              "<h2><span class=\"refentrytitle\">Class message_queue</span></h2>\n"
                              "<p>boost::interprocess::message_queue</p>\n"
                              "</div>\n"
                              "<h2 xmlns:rev=\"http://www.cs.rpi.edu/~gregod/boost/tools/doc/revision\" class=\"refsynopsisdiv-title\">Synopsis</h2>\n"
                              "<div xmlns:rev=\"http://www.cs.rpi.edu/~gregod/boost/tools/doc/revision\" class=\"refsynopsisdiv\"><pre class=\"synopsis\"><span class=\"comment\">// In header: &lt;<a class=\"link\" href=\"../../boost_interprocess_reference.html#header.boost.interprocess.ipc.message_queue_hpp\" title=\"Header &lt;boost/interprocess/ipc/message_queue.hpp&gt;\">boost/interprocess/ipc/message_queue.hpp</a>&gt;\n"
                              "\n"
                              "</span>\n"
                              "<span class=\"keyword\">class</span> <a class=\"link\" href=\"message_queue.html\" title=\"Class message_queue\">message_queue</a> <span class=\"special\">{</span>\n"
                              "<span class=\"keyword\">public</span><span class=\"special\">:</span>\n"
                              "  <span class=\"comment\">// <a class=\"link\" href=\"message_queue.html#boost.interprocess.message_queueconstruct-copy-destruct\">construct/copy/destruct</a></span>\n"
                              "  <a class=\"link\" href=\"message_queue.html#id909029-bb\"><span class=\"identifier\">message_queue</span></a><span class=\"special\">(</span><a class=\"link\" href=\"create_only_t.html\" title=\"Struct create_only_t\">create_only_t</a><span class=\"special\">,</span> <span class=\"keyword\">const</span> <span class=\"keyword\">char</span> <span class=\"special\">*</span><span class=\"special\">,</span> <span class=\"identifier\">std</span><span class=\"special\">::</span><span class=\"identifier\">size_t</span><span class=\"special\">,</span> <span class=\"identifier\">std</span><span class=\"special\">::</span><span class=\"identifier\">size_t</span><span class=\"special\">,</span> \n"
                              "                <span class=\"keyword\">const</span> <a class=\"link\" href=\"permissions.html\" title=\"Class permissions\">permissions</a> <span class=\"special\">&amp;</span> <span class=\"special\">=</span> <a class=\"link\" href=\"permissions.html\" title=\"Class permissions\">permissions</a><span class=\"special\">(</span><span class=\"special\">)</span><span class=\"special\">)</span><span class=\"special\">;</span>\n"
                              "  <a class=\"link\" href=\"message_queue.html#id909077-bb\"><span class=\"identifier\">message_queue</span></a><span class=\"special\">(</span><a class=\"link\" href=\"open_or_create_t.html\" title=\"Struct open_or_create_t\">open_or_create_t</a><span class=\"special\">,</span> <span class=\"keyword\">const</span> <span class=\"keyword\">char</span> <span class=\"special\">*</span><span class=\"special\">,</span> <span class=\"identifier\">std</span><span class=\"special\">::</span><span class=\"identifier\">size_t</span><span class=\"special\">,</span> <span class=\"identifier\">std</span><span class=\"special\">::</span><span class=\"identifier\">size_t</span><span class=\"special\">,</span> \n"
                              "                <span class=\"keyword\">const</span> <a class=\"link\" href=\"permissions.html\" title=\"Class permissions\">permissions</a> <span class=\"special\">&amp;</span> <span class=\"special\">=</span> <a class=\"link\" href=\"permissions.html\" title=\"Class permissions\">permissions</a><span class=\"special\">(</span><span class=\"special\">)</span><span class=\"special\">)</span><span class=\"special\">;</span>\n"
                              "  <a class=\"link\" href=\"message_queue.html#id909128-bb\"><span class=\"identifier\">message_queue</span></a><span class=\"special\">(</span><a class=\"link\" href=\"open_only_t.html\" title=\"Struct open_only_t\">open_only_t</a><span class=\"special\">,</span> <span class=\"keyword\">const</span> <span class=\"keyword\">char</span> <span class=\"special\">*</span><span class=\"special\">)</span><span class=\"special\">;</span>\n"
                              "  <a class=\"link\" href=\"message_queue.html#id909147-bb\"><span class=\"special\">~</span><span class=\"identifier\">message_queue</span></a><span class=\"special\">(</span><span class=\"special\">)</span><span class=\"special\">;</span>\n"
                              "\n"
                              "  <span class=\"comment\">// <a class=\"link\" href=\"message_queue.html#id908489-bb\">public member functions</a></span>\n"
                              "  <span class=\"special\">*</span><span class=\"keyword\">void</span> <a class=\"link\" href=\"message_queue.html#id908492-bb\"><span class=\"identifier\">send</span></a><span class=\"special\">(</span><span class=\"keyword\">const</span> <span class=\"keyword\">void</span> <span class=\"special\">*</span><span class=\"special\">,</span> <span class=\"identifier\">std</span><span class=\"special\">::</span><span class=\"identifier\">size_t</span><span class=\"special\">,</span> <span class=\"keyword\">unsigned</span> <span class=\"keyword\">int</span><span class=\"special\">)</span><span class=\"special\">;</span>\n"
                              "  <span class=\"keyword\">bool</span> <a class=\"link\" href=\"message_queue.html#id908794-bb\"><span class=\"identifier\">try_send</span></a><span class=\"special\">(</span><span class=\"keyword\">const</span> <span class=\"keyword\">void</span> <span class=\"special\">*</span><span class=\"special\">,</span> <span class=\"identifier\">std</span><span class=\"special\">::</span><span class=\"identifier\">size_t</span><span class=\"special\">,</span> <span class=\"keyword\">unsigned</span> <span class=\"keyword\">int</span><span class=\"special\">)</span><span class=\"special\">;</span>\n"
                              "  <span class=\"keyword\">bool</span> <a class=\"link\" href=\"message_queue.html#id908826-bb\"><span class=\"identifier\">timed_send</span></a><span class=\"special\">(</span><span class=\"keyword\">const</span> <span class=\"keyword\">void</span> <span class=\"special\">*</span><span class=\"special\">,</span> <span class=\"identifier\">std</span><span class=\"special\">::</span><span class=\"identifier\">size_t</span><span class=\"special\">,</span> <span class=\"keyword\">unsigned</span> <span class=\"keyword\">int</span><span class=\"special\">,</span> \n"
                              "                  <span class=\"keyword\">const</span> <span class=\"identifier\">boost</span><span class=\"special\">::</span><span class=\"identifier\">posix_time</span><span class=\"special\">::</span><span class=\"identifier\">ptime</span> <span class=\"special\">&amp;</span><span class=\"special\">)</span><span class=\"special\">;</span>\n"
                              "  <span class=\"keyword\">void</span> <a class=\"link\" href=\"message_queue.html#id908866-bb\"><span class=\"identifier\">receive</span></a><span class=\"special\">(</span><span class=\"keyword\">void</span> <span class=\"special\">*</span><span class=\"special\">,</span> <span class=\"identifier\">std</span><span class=\"special\">::</span><span class=\"identifier\">size_t</span><span class=\"special\">,</span> <span class=\"identifier\">std</span><span class=\"special\">::</span><span class=\"identifier\">size_t</span> <span class=\"special\">&amp;</span><span class=\"special\">,</span> <span class=\"keyword\">unsigned</span> <span class=\"keyword\">int</span> <span class=\"special\">&amp;</span><span class=\"special\">)</span><span class=\"special\">;</span>\n"
                              "  <span class=\"keyword\">bool</span> <a class=\"link\" href=\"message_queue.html#id908904-bb\"><span class=\"identifier\">try_receive</span></a><span class=\"special\">(</span><span class=\"keyword\">void</span> <span class=\"special\">*</span><span class=\"special\">,</span> <span class=\"identifier\">std</span><span class=\"special\">::</span><span class=\"identifier\">size_t</span><span class=\"special\">,</span> <span class=\"identifier\">std</span><span class=\"special\">::</span><span class=\"identifier\">size_t</span> <span class=\"special\">&amp;</span><span class=\"special\">,</span> <span class=\"keyword\">unsigned</span> <span class=\"keyword\">int</span> <span class=\"special\">&amp;</span><span class=\"special\">)</span><span class=\"special\">;</span>\n"
                              "  <span class=\"keyword\">bool</span> <a class=\"link\" href=\"message_queue.html#id908943-bb\"><span class=\"identifier\">timed_receive</span></a><span class=\"special\">(</span><span class=\"keyword\">void</span> <span class=\"special\">*</span><span class=\"special\">,</span> <span class=\"identifier\">std</span><span class=\"special\">::</span><span class=\"identifier\">size_t</span><span class=\"special\">,</span> <span class=\"identifier\">std</span><span class=\"special\">::</span><span class=\"identifier\">size_t</span> <span class=\"special\">&amp;</span><span class=\"special\">,</span> <span class=\"keyword\">unsigned</span> <span class=\"keyword\">int</span> <span class=\"special\">&amp;</span><span class=\"special\">,</span> \n"
                              "                     <span class=\"keyword\">const</span> <span class=\"identifier\">boost</span><span class=\"special\">::</span><span class=\"identifier\">posix_time</span><span class=\"special\">::</span><span class=\"identifier\">ptime</span> <span class=\"special\">&amp;</span><span class=\"special\">)</span><span class=\"special\">;</span>\n"
                              "  <span class=\"identifier\">std</span><span class=\"special\">::</span><span class=\"identifier\">size_t</span> <a class=\"link\" href=\"message_queue.html#id908989-bb\"><span class=\"identifier\">get_max_msg</span></a><span class=\"special\">(</span><span class=\"special\">)</span> <span class=\"keyword\">const</span><span class=\"special\">;</span>\n"
                              "  <span class=\"identifier\">std</span><span class=\"special\">::</span><span class=\"identifier\">size_t</span> <a class=\"link\" href=\"message_queue.html#id909003-bb\"><span class=\"identifier\">get_max_msg_size</span></a><span class=\"special\">(</span><span class=\"special\">)</span> <span class=\"keyword\">const</span><span class=\"special\">;</span>\n"
                              "  <span class=\"identifier\">std</span><span class=\"special\">::</span><span class=\"identifier\">size_t</span> <a class=\"link\" href=\"message_queue.html#id909017-bb\"><span class=\"identifier\">get_num_msg</span></a><span class=\"special\">(</span><span class=\"special\">)</span><span class=\"special\">;</span>\n"
                              "\n"
                              "  <span class=\"comment\">// <a class=\"link\" href=\"message_queue.html#id909158-bb\">public static functions</a></span>\n"
                              "  <span class=\"keyword\">static</span> <span class=\"keyword\">bool</span> <a class=\"link\" href=\"message_queue.html#id909162-bb\"><span class=\"identifier\">remove</span></a><span class=\"special\">(</span><span class=\"keyword\">const</span> <span class=\"keyword\">char</span> <span class=\"special\">*</span><span class=\"special\">)</span><span class=\"special\">;</span>\n"
                              "<span class=\"special\">}</span><span class=\"special\">;</span></pre></div>\n"
                              "<div class=\"refsect1\">\n"
                              "<a name=\"id1566809\"></a><h2>Description</h2>\n"
                              "<p>A class that allows sending messages between processes. </p>\n"
                              "<div class=\"refsect2\">\n"
                              "<a name=\"id1566815\"></a><h3>\n"
                              "<a name=\"boost.interprocess.message_queueconstruct-copy-destruct\"></a><code class=\"computeroutput\">message_queue</code> \n"
                              "        public\n"
                              "       construct/copy/destruct</h3>\n"
                              "<div class=\"orderedlist\"><ol class=\"orderedlist\" type=\"1\">\n"
                              "<li class=\"listitem\">\n"
                              "<pre class=\"literallayout\"><a name=\"id909029-bb\"></a><span class=\"identifier\">message_queue</span><span class=\"special\">(</span><a class=\"link\" href=\"create_only_t.html\" title=\"Struct create_only_t\">create_only_t</a> create_only<span class=\"special\">,</span> <span class=\"keyword\">const</span> <span class=\"keyword\">char</span> <span class=\"special\">*</span> name<span class=\"special\">,</span> \n"
                              "              <span class=\"identifier\">std</span><span class=\"special\">::</span><span class=\"identifier\">size_t</span> max_num_msg<span class=\"special\">,</span> <span class=\"identifier\">std</span><span class=\"special\">::</span><span class=\"identifier\">size_t</span> max_msg_size<span class=\"special\">,</span> \n"
                              "              <span class=\"keyword\">const</span> <a class=\"link\" href=\"permissions.html\" title=\"Class permissions\">permissions</a> <span class=\"special\">&amp;</span> perm <span class=\"special\">=</span> <a class=\"link\" href=\"permissions.html\" title=\"Class permissions\">permissions</a><span class=\"special\">(</span><span class=\"special\">)</span><span class=\"special\">)</span><span class=\"special\">;</span></pre>\n"
                              "<p>Creates a process shared message queue with name \"name\". For this message queue, the maximum number of messages will be \"max_num_msg\" and the maximum message size will be \"max_msg_size\". Throws on error and if the queue was previously created. </p>\n"
                              "</li>\n"
                              "<li class=\"listitem\">\n"
                              "<pre class=\"literallayout\"><a name=\"id909077-bb\"></a><span class=\"identifier\">message_queue</span><span class=\"special\">(</span><a class=\"link\" href=\"open_or_create_t.html\" title=\"Struct open_or_create_t\">open_or_create_t</a> open_or_create<span class=\"special\">,</span> <span class=\"keyword\">const</span> <span class=\"keyword\">char</span> <span class=\"special\">*</span> name<span class=\"special\">,</span> \n"
                              "              <span class=\"identifier\">std</span><span class=\"special\">::</span><span class=\"identifier\">size_t</span> max_num_msg<span class=\"special\">,</span> <span class=\"identifier\">std</span><span class=\"special\">::</span><span class=\"identifier\">size_t</span> max_msg_size<span class=\"special\">,</span> \n"
                              "              <span class=\"keyword\">const</span> <a class=\"link\" href=\"permissions.html\" title=\"Class permissions\">permissions</a> <span class=\"special\">&amp;</span> perm <span class=\"special\">=</span> <a class=\"link\" href=\"permissions.html\" title=\"Class permissions\">permissions</a><span class=\"special\">(</span><span class=\"special\">)</span><span class=\"special\">)</span><span class=\"special\">;</span></pre>\n"
                              "<p>Opens or creates a process shared message queue with name \"name\". If the queue is created, the maximum number of messages will be \"max_num_msg\" and the maximum message size will be \"max_msg_size\". If queue was previously created the queue will be opened and \"max_num_msg\" and \"max_msg_size\" parameters are ignored. Throws on error. </p>\n"
                              "</li>\n"
                              "<li class=\"listitem\">\n"
                              "<pre class=\"literallayout\"><a name=\"id909128-bb\"></a><span class=\"identifier\">message_queue</span><span class=\"special\">(</span><a class=\"link\" href=\"open_only_t.html\" title=\"Struct open_only_t\">open_only_t</a> open_only<span class=\"special\">,</span> <span class=\"keyword\">const</span> <span class=\"keyword\">char</span> <span class=\"special\">*</span> name<span class=\"special\">)</span><span class=\"special\">;</span></pre>\n"
                              "<p>Opens a previously created process shared message queue with name \"name\". If the was not previously created or there are no free resources, throws an error. </p>\n"
                              "</li>\n"
                              "<li class=\"listitem\">\n"
                              "<pre class=\"literallayout\"><a name=\"id909147-bb\"></a><span class=\"special\">~</span><span class=\"identifier\">message_queue</span><span class=\"special\">(</span><span class=\"special\">)</span><span class=\"special\">;</span></pre>\n"
                              "<p>Destroys *this and indicates that the calling process is finished using the resource. All opened message queues are still valid after destruction. The destructor function will deallocate any system resources allocated by the system for use by this process for this resource. The resource can still be opened again calling the open constructor overload. To erase the message queue from the system use remove(). </p>\n"
                              "</li>\n"
                              "</ol></div>\n"
                              "</div>\n"
                              "<div class=\"refsect2\">\n"
                              "<a name=\"id1567241\"></a><h3>\n"
                              "<a name=\"id908489-bb\"></a><code class=\"computeroutput\">message_queue</code> public member functions</h3>\n"
                              "<div class=\"orderedlist\"><ol class=\"orderedlist\" type=\"1\">\n"
                              "<li class=\"listitem\">\n"
                              "<pre class=\"literallayout\"><span class=\"special\">*</span><span class=\"keyword\">void</span> <a name=\"id908492-bb\"></a><span class=\"identifier\">send</span><span class=\"special\">(</span><span class=\"keyword\">const</span> <span class=\"keyword\">void</span> <span class=\"special\">*</span> buffer<span class=\"special\">,</span> <span class=\"identifier\">std</span><span class=\"special\">::</span><span class=\"identifier\">size_t</span> buffer_size<span class=\"special\">,</span> \n"
                              "           <span class=\"keyword\">unsigned</span> <span class=\"keyword\">int</span> priority<span class=\"special\">)</span><span class=\"special\">;</span></pre>\n"
                              "<p>Sends a message stored in buffer \"buffer\" with size \"buffer_size\" in the message queue with priority \"priority\". If the message queue is full the sender is blocked. Throws interprocess_error on error. </p>\n"
                              "</li>\n"
                              "<li class=\"listitem\">\n"
                              "<pre class=\"literallayout\"><span class=\"keyword\">bool</span> <a name=\"id908794-bb\"></a><span class=\"identifier\">try_send</span><span class=\"special\">(</span><span class=\"keyword\">const</span> <span class=\"keyword\">void</span> <span class=\"special\">*</span> buffer<span class=\"special\">,</span> <span class=\"identifier\">std</span><span class=\"special\">::</span><span class=\"identifier\">size_t</span> buffer_size<span class=\"special\">,</span> \n"
                              "              <span class=\"keyword\">unsigned</span> <span class=\"keyword\">int</span> priority<span class=\"special\">)</span><span class=\"special\">;</span></pre>\n"
                              "<p>Sends a message stored in buffer \"buffer\" with size \"buffer_size\" through the message queue with priority \"priority\". If the message queue is full the sender is not blocked and returns false, otherwise returns true. Throws interprocess_error on error. </p>\n"
                              "</li>\n"
                              "<li class=\"listitem\">\n"
                              "<pre class=\"literallayout\"><span class=\"keyword\">bool</span> <a name=\"id908826-bb\"></a><span class=\"identifier\">timed_send</span><span class=\"special\">(</span><span class=\"keyword\">const</span> <span class=\"keyword\">void</span> <span class=\"special\">*</span> buffer<span class=\"special\">,</span> <span class=\"identifier\">std</span><span class=\"special\">::</span><span class=\"identifier\">size_t</span> buffer_size<span class=\"special\">,</span> \n"
                              "                <span class=\"keyword\">unsigned</span> <span class=\"keyword\">int</span> priority<span class=\"special\">,</span> \n"
                              "                <span class=\"keyword\">const</span> <span class=\"identifier\">boost</span><span class=\"special\">::</span><span class=\"identifier\">posix_time</span><span class=\"special\">::</span><span class=\"identifier\">ptime</span> <span class=\"special\">&amp;</span> abs_time<span class=\"special\">)</span><span class=\"special\">;</span></pre>\n"
                              "<p>Sends a message stored in buffer \"buffer\" with size \"buffer_size\" in the message queue with priority \"priority\". If the message queue is full the sender retries until time \"abs_time\" is reached. Returns true if the message has been successfully sent. Returns false if timeout is reached. Throws interprocess_error on error. </p>\n"
                              "</li>\n"
                              "<li class=\"listitem\">\n"
                              "<pre class=\"literallayout\"><span class=\"keyword\">void</span> <a name=\"id908866-bb\"></a><span class=\"identifier\">receive</span><span class=\"special\">(</span><span class=\"keyword\">void</span> <span class=\"special\">*</span> buffer<span class=\"special\">,</span> <span class=\"identifier\">std</span><span class=\"special\">::</span><span class=\"identifier\">size_t</span> buffer_size<span class=\"special\">,</span> <span class=\"identifier\">std</span><span class=\"special\">::</span><span class=\"identifier\">size_t</span> <span class=\"special\">&amp;</span> recvd_size<span class=\"special\">,</span> \n"
                              "             <span class=\"keyword\">unsigned</span> <span class=\"keyword\">int</span> <span class=\"special\">&amp;</span> priority<span class=\"special\">)</span><span class=\"special\">;</span></pre>\n"
                              "<p>Receives a message from the message queue. The message is stored in buffer \"buffer\", which has size \"buffer_size\". The received message has size \"recvd_size\" and priority \"priority\". If the message queue is empty the receiver is blocked. Throws interprocess_error on error. </p>\n"
                              "</li>\n"
                              "<li class=\"listitem\">\n"
                              "<pre class=\"literallayout\"><span class=\"keyword\">bool</span> <a name=\"id908904-bb\"></a><span class=\"identifier\">try_receive</span><span class=\"special\">(</span><span class=\"keyword\">void</span> <span class=\"special\">*</span> buffer<span class=\"special\">,</span> <span class=\"identifier\">std</span><span class=\"special\">::</span><span class=\"identifier\">size_t</span> buffer_size<span class=\"special\">,</span> \n"
                              "                 <span class=\"identifier\">std</span><span class=\"special\">::</span><span class=\"identifier\">size_t</span> <span class=\"special\">&amp;</span> recvd_size<span class=\"special\">,</span> <span class=\"keyword\">unsigned</span> <span class=\"keyword\">int</span> <span class=\"special\">&amp;</span> priority<span class=\"special\">)</span><span class=\"special\">;</span></pre>\n"
                              "<p>Receives a message from the message queue. The message is stored in buffer \"buffer\", which has size \"buffer_size\". The received message has size \"recvd_size\" and priority \"priority\". If the message queue is empty the receiver is not blocked and returns false, otherwise returns true. Throws interprocess_error on error. </p>\n"
                              "</li>\n"
                              "<li class=\"listitem\">\n"
                              "<pre class=\"literallayout\"><span class=\"keyword\">bool</span> <a name=\"id908943-bb\"></a><span class=\"identifier\">timed_receive</span><span class=\"special\">(</span><span class=\"keyword\">void</span> <span class=\"special\">*</span> buffer<span class=\"special\">,</span> <span class=\"identifier\">std</span><span class=\"special\">::</span><span class=\"identifier\">size_t</span> buffer_size<span class=\"special\">,</span> \n"
                              "                   <span class=\"identifier\">std</span><span class=\"special\">::</span><span class=\"identifier\">size_t</span> <span class=\"special\">&amp;</span> recvd_size<span class=\"special\">,</span> <span class=\"keyword\">unsigned</span> <span class=\"keyword\">int</span> <span class=\"special\">&amp;</span> priority<span class=\"special\">,</span> \n"
                              "                   <span class=\"keyword\">const</span> <span class=\"identifier\">boost</span><span class=\"special\">::</span><span class=\"identifier\">posix_time</span><span class=\"special\">::</span><span class=\"identifier\">ptime</span> <span class=\"special\">&amp;</span> abs_time<span class=\"special\">)</span><span class=\"special\">;</span></pre>\n"
                              "<p>Receives a message from the message queue. The message is stored in buffer \"buffer\", which has size \"buffer_size\". The received message has size \"recvd_size\" and priority \"priority\". If the message queue is empty the receiver retries until time \"abs_time\" is reached. Returns true if the message has been successfully sent. Returns false if timeout is reached. Throws interprocess_error on error. </p>\n"
                              "</li>\n"
                              "<li class=\"listitem\">\n"
                              "<pre class=\"literallayout\"><span class=\"identifier\">std</span><span class=\"special\">::</span><span class=\"identifier\">size_t</span> <a name=\"id908989-bb\"></a><span class=\"identifier\">get_max_msg</span><span class=\"special\">(</span><span class=\"special\">)</span> <span class=\"keyword\">const</span><span class=\"special\">;</span></pre>\n"
                              "<p>Returns the maximum number of messages allowed by the queue. The message queue must be opened or created previously. Otherwise, returns 0. Never throws </p>\n"
                              "</li>\n"
                              "<li class=\"listitem\">\n"
                              "<pre class=\"literallayout\"><span class=\"identifier\">std</span><span class=\"special\">::</span><span class=\"identifier\">size_t</span> <a name=\"id909003-bb\"></a><span class=\"identifier\">get_max_msg_size</span><span class=\"special\">(</span><span class=\"special\">)</span> <span class=\"keyword\">const</span><span class=\"special\">;</span></pre>\n"
                              "<p>Returns the maximum size of message allowed by the queue. The message queue must be opened or created previously. Otherwise, returns 0. Never throws </p>\n"
                              "</li>\n"
                              "<li class=\"listitem\">\n"
                              "<pre class=\"literallayout\"><span class=\"identifier\">std</span><span class=\"special\">::</span><span class=\"identifier\">size_t</span> <a name=\"id909017-bb\"></a><span class=\"identifier\">get_num_msg</span><span class=\"special\">(</span><span class=\"special\">)</span><span class=\"special\">;</span></pre>\n"
                              "<p>Returns the number of messages currently stored. Never throws </p>\n"
                              "</li>\n"
                              "</ol></div>\n"
                              "</div>\n"
                              "<div class=\"refsect2\">\n"
                              "<a name=\"id1568146\"></a><h3>\n"
                              "<a name=\"id909158-bb\"></a><code class=\"computeroutput\">message_queue</code> public static functions</h3>\n"
                              "<div class=\"orderedlist\"><ol class=\"orderedlist\" type=\"1\"><li class=\"listitem\">\n"
                              "<pre class=\"literallayout\"><span class=\"keyword\">static</span> <span class=\"keyword\">bool</span> <a name=\"id909162-bb\"></a><span class=\"identifier\">remove</span><span class=\"special\">(</span><span class=\"keyword\">const</span> <span class=\"keyword\">char</span> <span class=\"special\">*</span> name<span class=\"special\">)</span><span class=\"special\">;</span></pre>\n"
                              "<p>Removes the message queue from the system. Returns false on error. Never throws </p>\n"
                              "</li></ol></div>\n"
                              "</div>\n"
                              "</div>\n"
                              "</div>\n"
                              "<table xmlns:rev=\"http://www.cs.rpi.edu/~gregod/boost/tools/doc/revision\" width=\"100%\"><tr>\n"
                              "<td align=\"left\"></td>\n"
                              "<td align=\"right\"><div class=\"copyright-footer\">Copyright &#169; 2005-2010 Ion Gaztanaga<p>\n"
                              "        Distributed under the Boost Software License, Version 1.0. (See accompanying\n"
                              "        file LICENSE_1_0.txt or copy at <a href=\"http://www.boost.org/LICENSE_1_0.txt\" target=\"_top\">http://www.boost.org/LICENSE_1_0.txt</a>)\n"
                              "      </p>\n"
                              "</div></td>\n"
                              "</tr></table>\n"
                              "<hr>\n"
                              "<div class=\"spirit-nav\">\n"
                              "<a accesskey=\"p\" href=\"unordered_map_index.html\"><img src=\"../../../../doc/src/images/prev.png\" alt=\"Prev\"></a><a accesskey=\"u\" href=\"../../boost_interprocess_reference.html#header.boost.interprocess.ipc.message_queue_hpp\"><img src=\"../../../../doc/src/images/up.png\" alt=\"Up\"></a><a accesskey=\"h\" href=\"../../index.html\"><img src=\"../../../../doc/src/images/home.png\" alt=\"Home\"></a><a accesskey=\"n\" href=\"basic_managed_external__id909193.html\"><img src=\"../../../../doc/src/images/next.png\" alt=\"Next\"></a>\n"
                              "</div>\n"
                              "</body>\n"
                              "</html>";
        boost::asio::async_write(sock_ , boost::asio::buffer(respond , 26789) ,
                                 [](const boost::system::error_code &error , std::size_t bytes_transferred) {
                                     if (!error) {
                                         std::cout << "已发送字节数: " << bytes_transferred << std::endl;
                                     }
                                     std::cout << error.value() << error.message() << std::endl;
                                 });
    }

private:
    void do_acceptor() {
        acceptor_.async_accept([this](const boost::system::error_code &error , boost::asio::ip::tcp::socket peer) {
            std::cout << "async_accept: " << error.value() << ": " << error.message() << std::endl;
//            peer.async_write_some(boost::asio::buffer("data_" , 10) ,
//                                  [](const boost::system::error_code &err , // Result of operation.
//                                     std::size_t bytes_transferred) {
//                                      std::cout << err.value() << ": " << err.message() << std::endl;
//                                  });
            do_write();
//            do_read();
        });
    }
};


class asynClient {

private:
    boost::asio::io_context &io_context_;
    tcp::socket socket_;
    struct msg_data {
        char data_[MAX_DATA_SIZE] {};
        int i1_ {};
        long l1_ {};
    } msg_data_ {};
    char *ip_ {};
    char *port_ {};
public:
    asynClient(boost::asio::io_context &ioContext , const tcp::resolver::results_type &endpoints) : io_context_(
            ioContext) , socket_(ioContext) {
//        tcp::resolver resolver(ioContext);
//        auto endpoints = resolver.resolve(argv[1] , argv[2]);
        do_connect(endpoints);
    }

    asynClient(boost::asio::io_context &ioContext , const char *ip , const char *service) : io_context_(ioContext) ,
                                                                                            socket_(ioContext) ,
                                                                                            ip_(const_cast<char *>(ip)) ,
                                                                                            port_(const_cast<char *>(service)) {
        tcp::resolver r(ioContext);
        tcp::resolver::query q(ip , service);
        r.async_resolve(q , [this](const boost::system::error_code &ec , const tcp::resolver::results_type &results) {
            if (!ec) {
                do_connect(results);
            }
        });

    }

    void do_read() {
        boost::asio::async_read(socket_ , boost::asio::buffer(msg_data_.data_ , MAX_DATA_SIZE) ,
                                [&](const boost::system::error_code &error , std::size_t bytes_transferred) {
                                    if (!error)
                                        if (strlen(msg_data_.data_) < MIN_DATA_SIZE) {
                                            std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
                                        }
                                    std::cout << msg_data_.data_ << std::endl;
                                    do_read();
                                });
    }

    void do_write(const char *da) {
        boost::asio::async_write(socket_ , boost::asio::buffer(msg_data_.data_ , MAX_DATA_SIZE) ,
                                 [](const boost::system::error_code &error , std::size_t bytes_transferred) {
                                     if (!error) {
                                         std::cout << "已发送字节数: " << bytes_transferred << std::endl;
                                     }
                                 });
    }

private:
    void do_connect(const tcp::resolver::results_type &endpoints) {
        boost::asio::async_connect(socket_ , endpoints , [this](boost::system::error_code ec , const tcp::endpoint &) {
            if (!ec) {
                do_read();
            }
        });
    }


};

void asio_test() {
    std::cout << boost::asio::ip::host_name() << std::endl;
//    syn_server();
//    syn_client();
//    asyn_client();
//    asyn_server();
    boost::asio::io_context ioContext;

    tcp::endpoint endpoint(tcp::v4() , 9110);
    boost::asio::ip::tcp::socket sock(ioContext);
//    asynServer server(ioContext , endpoint , std::move(sock));

    tcp::resolver resolver(ioContext);
    auto endpoints = resolver.resolve("10.1.0.158" , "9110");
//    auto endpoints = resolver.resolve(endpoint);
//    asynClient client(ioContext , endpoints);
//    asynClient client(ioContext , "10.1.0.158" , "9110");

//    tcp::iostream s("" , "");
//    ioContext.run();

}

int main(int argc , char **argv) {

    boost::asio::io_context ioContext;
//    asynClient client(ioContext , "10.1.0.158" , "9110");

    tcp::endpoint endpoint(tcp::v4() , 9110);
    boost::asio::ip::tcp::socket sock(ioContext);
    asynServer server(ioContext , endpoint , std::move(sock));
    ioContext.run();

}