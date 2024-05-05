#include "MateriaSource.hpp"

AMateria **MateriaSource::tracker = new AMateria*[10];
int MateriaSource::trackCnt = 0;

MateriaSource::MateriaSource() : targetMold(0)
{
    for (int i = 0; i < 4; i++)
        mold[i] = NULL;
    for (int i = 0; i < 10; i++)
        tracker[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
    *this = copy;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < 4; i++)
        {
            if (mold[i] != NULL)
            {
                delete (mold[i]);
                mold[i] = NULL;
            }
            if (rhs.mold[i] != NULL)
            {
                mold[i] = rhs.mold[i]->clone();
            }
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < targetMold; i++)
    {
        if (mold[i] != NULL)
            delete (mold[i]);
    }
    for (int i = 0; i < trackCnt; i++)
    {
        if (tracker[i] != NULL)
        {
            std::cout << "Deleting " << i << "th AMateria" << std::endl;
            delete (tracker[i]);    
        }
    }
    delete [] tracker;
}

bool MateriaSource::isTrackable(AMateria* target)
{
    for (int i = 0; i < trackCnt; i++)
    {
        if (tracker[i] == target)
            return (true);
    }
    return (false);
}

void MateriaSource::untrack(AMateria* target)
{
    for (int i = 0; i < trackCnt; i++)
    {
        if (tracker[i] == target)
        {
            tracker[i] = NULL;
            return;
        }
    }
}

void MateriaSource::track(AMateria* target)
{
    if (trackCnt && trackCnt % 10 == 0)
    {
        AMateria **tmp = new AMateria*[trackCnt + 10];
        for (int i = 0; i < trackCnt; i++)
        {
            tmp[i] = tracker[i];
        }
        trackCnt++;
        delete [] tracker;
        tracker = tmp;
    }
    tracker[trackCnt++] = target;
}

void MateriaSource::learnMateria(AMateria* target)
{
    if (targetMold > 3)
        return ;
    mold[targetMold++] = target;
}

AMateria *MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < targetMold; i++)
    {
        if (mold[i]->getType() == type)
        {
            AMateria *newAMateria = mold[i]->clone();
            track(newAMateria);
            return (newAMateria);
        }
    }
    std::cout << "Can't create such Materia" << std::endl;
    return (0);
}