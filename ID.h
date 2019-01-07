#ifndef ID_H
#define ID_H

/*
 * A home made, very reliable and 100% not unique ids
 * used to distinguish files.
 * 
 * It's like GUID, but better. How you ask? I made it.
 */
class ID
{
private:
	unsigned long long m_id = 0;
public:
	ID();
	~ID();
	unsigned long long GetID();
	static unsigned long long GenerateID();
};

#endif