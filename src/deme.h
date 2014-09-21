#pragma once

#include "organism.h"
#include "organismsbuffer.h"


namespace NEAT {

    class Deme {
    public:
        Deme(rng_t rng,
             std::vector<std::unique_ptr<Genome>> &seeds,
             size_t size,
             size_t population_index);
        ~Deme();

        void evaluate(std::function<void (Organism &org)> eval_org);
        Organism &get_fittest();
		void next_generation(std::vector<Organism *> &elites,
                             class GenomeManager *genome_manager);
        void create_phenotypes();

		void write(std::ostream& out);

        void verify();
    private:
        OrganismsBuffer<Organism> orgs;
        size_t population_index;
        int generation;
    };

}
