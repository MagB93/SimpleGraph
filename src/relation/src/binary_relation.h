#include <set>
#include <stdio.h>
#include "pair.h"

template<typename E1, typename E2> class BinaryRelation{
    
    private: 
        std::set<Pair<E1, E2> > pair_set; // Edges
        std::set<E1> input_set; // entry set
        std::set<E2> target_set; // image set

    public:

        // Big 3 methods
        BinaryRelation<E1, E2>(){
            pair_set = std::set<Pair<E1, E2> >(); 
            input_set = std::set<E1>();
            target_set = std::set<E2>();
        };
        
        BinaryRelation<E1, E2>(const BinaryRelation<E1, E2> &binrel){
            BinaryRelation<E1, E2> cp_binrel = new BinaryRelation();
            (*cp_binrel.pair_set) = *binrel.pair_set;
            (*cp_binrel.input_set) = *binrel.preImage;
            (*cp_binrel.target_set) = *binrel.image;
        };
        
        BinaryRelation<E1, E2>(const E1 &inputset, const E2 &targetset){
            BinaryRelation<E1, E2> cp_binrel = new BinaryRelation();
            (*cp_binrel.input_set) = *inputset;
            (*cp_binrel.target_set) = *targetset;
        };

        ~BinaryRelation<E1, E2>(){
            ~pair_set();
            ~input_set();
            ~target_set();
        };

        // ====== Methods for adding/ removing data
        bool add(E1 first, E2 second){
            input_set.emplace(first);
            target_set.emplace(second);
            return pair_set.emplace(first, second); //return true if the pair was inserted
        };

        bool remove(E1 first, E2 second){

            // Variables for checking the deletion of th  
            bool del_pre, del_post;

            del_pre = remove_from_pretarget_set(first);
            del_post = remove_from_target_set(second);

            if(del_pre && del_post){
                remove_pair(first, second);
            }
            else{
                printf("Can't remove a pair, which isn't in the input_set or target_set.");
            }

        };

        bool remove_pair(E1 first, E2 second){
            return check_and_erase<Pair<E1, E2> >(pair_set, Pair<E1, E2>(first, second));

        }

        bool remove_from_pretarget_set(E1 first){
            return check_and_erase<E1>(input_set, first);
        }

        bool remove_from_target_set(E2 second){
            return check_and_erase<E2>(target_set, second);
        }

        template<typename T> bool check_and_erase(std::set<T> templ_set, T key){
            auto search_key = templ_set.find(key);

            if (search_key != templ_set.end()){
                return templ_set.erase(search_key);
            }
            else{
                return false;
            };
        };

        // =========================== Methods for manipulation the data.
        BinaryRelation<E2, E1> transposition(){
            
            BinaryRelation<E2, E1> bin = new BinaryRelation();
            
            for(auto it = pair_set.begin(); it != pair_set.end(); ++it){
                
                bin.emplace(it.getSecond(), it.getFirst());
            }

            return bin;
        };

        template<typename E3> BinaryRelation<E1, E3> 
            product(BinaryRelation<E2, E3> relation){

            BinaryRelation<E1, E3> bin = new BinaryRelation();

            for(auto it1 = pair_set.begin(); it1 != pair_set.end(); ++it1){

                for(auto it2 = relation.pair_set.begin(); 
                    it2 != relation.pair_set.end(); ++it2){
                        if(it1 <= it2){
                            bin.add(it1.getFirst(), it2.getSecond());
                        }
                    }
            }

        };


        // Getter & Setters
        inline std::set<E1> get_input_set(){
            return input_set;
        };
        
        inline std::set<E2> get_target_set(){
            return target_set;
        };

        inline std::set<Pair<E1, E2> > get_pair_set(){
            return pair_set;
        };

        void inline set_input_set(const std::set<E1> &input){
            *input_set = *input;
        };

        void inline set_target_set(const std::set<E2> &target){
            *target_set = *target;
        };

        void inline set_pair_set(const std::set<Pair<E1, E2> > &pairs){
            *pair_set = *pairs;
        };
           
        // Operators
        bool operator==(const BinaryRelation<E1, E2> &comp_rel){

            // Compare all values of this-> against the passed one using the stl
            return (this->input_set == comp_rel.input_set &&
                    this->target_set == comp_rel.target_set &&
                    this->pair_set == comp_rel.pair_set);

        };

};