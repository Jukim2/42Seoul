#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        static AMateria **tracker;
        static int trackCnt;
        AMateria *mold[4];
        int targetMold;
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& copy);
        MateriaSource& operator=(const MateriaSource& rhs);
        ~MateriaSource();

        static void untrack(AMateria*);
        static bool isTrackable(AMateria*);
        static void track(AMateria*);
        void learnMateria(AMateria*);
        AMateria *createMateria(std::string const & type);
};

#endif