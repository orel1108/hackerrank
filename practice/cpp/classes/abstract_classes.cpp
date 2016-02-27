class LRUCache : public Cache
{
public:
    LRUCache(int i_capacity)
        : m_cp(i_capacity)
        , m_size(0)
    {
        head = tail = NULL;
    }

    void set(int i_key, int i_value)
    {
        map < int, Node* >::iterator it;
        it = mp.find(i_key);
        if (it != mp.end())
            it->second->value = i_value;
        else
        {
            Node * node = new Node(NULL, NULL, i_key, i_value);

            if (head == NULL)
            {
                head = node;
                tail = node;
            }
            else
            {
                Node * tmp = head;
                node->next = tmp;
                head = node;
                tmp->prev = head;
            }
            mp.insert(make_pair(i_key, node));

            m_size++;
            if (m_size > m_cp)
            {
                Node * tailnode = tail->prev;
                map< int, Node* >::iterator it;
                for (it = mp.begin(); it != mp.end(); ++it)
                {
                    if (it->second == tail)
                    {
                        mp.erase(it);
                        break;
                    }
                }
                tailnode->next = NULL;
                delete(tail);
                tail = tailnode;
            }
        }
    }

    int get(int i_key)
    {
        map< int, Node* >::iterator it;
        it = mp.find(i_key);
        if (it != mp.end())
            return it->second->value;
        return -1;

    }

private:
    int m_cp, m_size;
};
