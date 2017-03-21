#include "binary_relation.h" 
#include <set>


template<typename E1, typename E2> class HeterogeneRelation:
    public BinaryRelation<E1, E2>{
        
        public:
            // Constructors
            HeterogeneRelation<E1, E2>(const E1 &input_set, const E2 *target_set): 
                BinaryRelation<E1, E2>(input_set, target_set){};
            
            // ================== Methods for checking graphproperties
            bool isLeftTotal(){
                HeterogeneRelation<E1, E2> hetallrel = 
                    this->template get_allrelation<HeterogeneRelation<E1, E2> >();

                BinaryRelation<E1, E1> bin_prod_hetall = 
                    this->template product<E1>(hetallrel);

                HeterogeneRelation<E1, E1> reference_allrel = 
                    this->template get_allrelation<HeterogeneRelation<E1, E1> >();

               return reference_allrel == bin_prod_hetall;
            };

            bool isRightTotal;
            bool isRightUnique;
            bool isLeftUnique;

            // Methods for creating 'standard' utility object, e.g. the allrelation
            HeterogeneRelation<E1, E2> get_allrelation(const HeterogeneRelation<E1, E2> &relation){
                HeterogeneRelation<E1, E2> all_rel =
                    HeterogeneRelation(&relation.input_set, &relation.target_set);

                all_rel.set_input_set(this->input_set);
                all_rel.set_target_set(this->target_set);

                for(auto i = all_rel.input_set.begin(); i != all_rel.input_set.end(); ++i)
                {
                    for(auto j = all_rel.target_set.begin(); j != all_rel.target_set.end(); ++j)
                    {
                        all_rel.add(i, j);
                    }
                    
                }

                return all_rel;

            };

            // Operators

            bool operator==(const HeterogeneRelation<E1, E2> comp_rel){
                return BinaryRelation<E1, E2>::operator == (comp_rel);
            }
    };
