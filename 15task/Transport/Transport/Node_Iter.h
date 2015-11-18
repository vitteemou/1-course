class Node_Iter {
   public:
	Node_Iter() : basicIter()
	{
	}

	Node_Iter(Nvector_iter& basic)
	{
	       basicIter = basic;
        }

        int operator *()
	{
		return (**basicIter).number;
	}

	Node_Iter& operator ++(int)
	{
		++basicIter;
		return *this;
        }
  
	bool operator == (Node_Iter& obj)
	{
		return (basicIter == obj.basicIter);
	}


	bool operator != (Node_Iter& obj)
	{
		return (basicIter != obj.basicIter);
	}

 private:
	Nvector_iter basicIter;

};
