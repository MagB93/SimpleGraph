
#include <set>
#include <stdio.h>
#include "binary_relation.h" 

#ifndef HET_REL_N
#define HET_REL_N
template<typename E1, typename E2> class HeterogeneRelation:
    public BinaryRelation<E1, E2>{
        
        public:
            // Constructors
            HeterogeneRelation<E1, E2>(const E1 &input_set, const E2 *target_set): 
                BinaryRelation<E1, E2>(input_set, target_set){};
            
            // ================== Methods for checking graphproperties

            /** Check wether the relation is a left total one.
            * It return true in case each input_set value has **at least** one connection to an element in the target_set
            * @param none
            */
            bool isLeftTotal(){
                HeterogeneRelation<E1, E2> hetallrel = 
                    this->template get_allrelation<HeterogeneRelation<E1, E2> >();

                BinaryRelation<E1, E1> bin_prod_hetall = 
                    this->template product<E1>(hetallrel);

                HeterogeneRelation<E1, E1> reference_allrel = 
                    this->template get_allrelation<HeterogeneRelation<E1, E1> >();

               return reference_allrel == bin_prod_hetall;
            };

            /** Check wether the relation is a right total one.
            * It return true in case each target_set value has **at least** one connection to an element in the input_set
            * @param none
            */
            bool isRightTotal(){
                HeterogeneRelation<E2, E1> het_transall = 
                    this->template get_allrelation<HeterogeneRelation<E2, E1> >();
                BinaryRelation<E2, E2> bin_prod_hetall = 
                    this->template product<E2>(het_transall);

                HeterogeneRelation<E2, E2> reference_allrel =
                    this->template get_allrelation<HeterogeneRelation<E2, E2> >(het_transall);

                return reference_allrel == bin_prod_hetall;
            
            };


            /** Check wether the relation is a left total one.
            * The function returns true, in case each element in the target_set value has **at most** one element in the input_set
            */
            bool isLeftUnique(){
                BinaryRelation<E2, E1> transp_rel = 
                    this->tranpose();
                
                BinaryRelation<E1, E1> prod_transp_rel =
                    this->template product<E1>(transp_rel);
                
                try{
                    BinaryRelation<E1, E2> identity =
                        this->get_identity();
                    return prod_transp_rel <= identity;
                }
                catch(const char* msg){
                    std::cout << msg << std::endl;
                    return false;
                }

            };
            
            /** Check wether the relation is a right total one.
            * The function returns true, in case each element in the target_set value has **at most** one element in the input_set
            */
            bool isRightUnique(){
                BinaryRelation<E2, E1> transp_rel = 
                    this->tranpose();
                
                BinaryRelation<E2, E2> prod_transp_rel =
                    this->template product<E2>(transp_rel);
                
                try{
                    BinaryRelation<E1, E2> identity =
                        this->get_identity();
                    return prod_transp_rel <= identity;
                }
                catch(const char* msg){
                    std::cout << msg << std::endl;
                    return false;
                }


            };


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

#endif